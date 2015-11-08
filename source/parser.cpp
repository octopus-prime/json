/*
 * parser.cpp
 *
 *  Created on: 31.01.2015
 *      Author: mike_gresens
 */

#include <json/value.hpp>
#include <json/parser.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/fusion/include/std_pair.hpp>
#include <boost/phoenix/bind.hpp>
#include <boost/format.hpp>

namespace boost {

// NOTE: This should be part of boost !!!

template <typename Iterator>
utf8_output_iterator<Iterator>
make_utf8_output_iterator(Iterator iterator)
{
	return utf8_output_iterator<Iterator>(iterator);
}

}

using namespace std::string_literals;

namespace qi = boost::spirit::qi;
namespace px = boost::phoenix;

namespace json {
namespace impl {

template <typename Iterator, typename Skipper>
class parser
:
	public qi::grammar<Iterator, Skipper, value_t()>
{
public:
	parser();

protected:
	static void append(string_t& string, const char32_t character);

private:
	qi::rule<Iterator, Skipper, value_t()> _value;
	qi::symbols<char, null_t> _null;
	qi::rule<Iterator, Skipper, bool_t()> _boolean;
	qi::rule<Iterator, Skipper, number_t()> _number;
	qi::rule<Iterator, Skipper, string_t()> _string;
	qi::symbols<char, char> _special;
	qi::rule<Iterator, void(string_t&)> _unicode;
	qi::rule<Iterator, Skipper, array_t()> _array;
	qi::rule<Iterator, Skipper, object_t()> _object;
	qi::rule<Iterator, Skipper, std::pair<string_t,value_t>()> _member;
};

template <typename Iterator, typename Skipper>
parser<Iterator, Skipper>::parser()
:
	parser::base_type(_value),
	_value("value"s),
	_null("null"s),
	_boolean("boolean"s),
	_number("number"s),
	_string("string"s),
	_special("special"s),
	_unicode("unicode"s),
	_array("array"s),
	_object("object"s),
	_member("member"s)
{
	_value = _null | _boolean | _number | _string | _array | _object;
	_null.add("null", null_t());
	_boolean = qi::bool_;
	_number = qi::double_;
	_string = qi::lexeme[qi::lit('"') > *(_special | _unicode(qi::_val) | (qi::char_ - qi::lit('"') - qi::lit('\\') - qi::cntrl)) > qi::lit('"')];
	_special.add("\\\"", '\"')("\\\\", '\\')("\\/", '/')("\\b", '\b')("\\f", '\f')("\\n", '\n')("\\r", '\r')("\\t", '\t');
	_unicode = qi::lit("\\u") > qi::uint_parser<char32_t, 16, 4, 4>() [px::bind(append, qi::_r1, qi::_1)];
	_array = qi::lit('[') > -(_value % qi::lit(',')) > qi::lit(']');
	_object = qi::lit('{') > -(_member % qi::lit(',')) > qi::lit('}');
	_member = _string > qi::lit(':') > _value;
}

template <typename Iterator, typename Skipper>
void
parser<Iterator, Skipper>::append(string_t& string, const char32_t character)
{
	*boost::make_utf8_output_iterator(std::back_inserter(string)) = character;
}

class parser_exception
:
	public json::parser_exception
{
public:
	virtual const char* what() const noexcept;
};

const char*
parser_exception::what() const noexcept
{
	return "parse failed.";
}

class expectation_exception
:
	public json::parser_exception
{
public:
	template <typename Iterator>
	explicit expectation_exception(const qi::expectation_failure<Iterator>& exception);

	virtual const char* what() const noexcept;

protected:
	template <typename Iterator>
	static std::string build(const qi::expectation_failure<Iterator>& exception);

private:
	std::string _what;
};

template <typename Iterator>
expectation_exception::expectation_exception(const qi::expectation_failure<Iterator>& exception)
:
	_what(build(exception))
{
}

const char*
expectation_exception::what() const noexcept
{
	return _what.c_str();
}

template <typename Iterator>
std::string
expectation_exception::build(const qi::expectation_failure<Iterator>& exception)
{
	boost::format what("Expected %s but found \"%s\".");
	what % exception.what_ % std::string(exception.first, std::min(exception.first + 20, exception.last));
	return what.str();
}

}

value_t
parse(const std::string& string)
{
	typedef std::string::const_iterator input_iterator;

	value_t value;
	input_iterator begin = string.begin();
	const input_iterator end = string.end();
	const impl::parser<input_iterator, qi::space_type> parser;

	try
	{
		const bool success = qi::phrase_parse(begin, end, parser, qi::space, value);
		if (!success || begin != end)
			throw impl::parser_exception();
	}
	catch(const qi::expectation_failure<input_iterator>& exception)
	{
		throw impl::expectation_exception(exception);
	}

	return value;
}

}
