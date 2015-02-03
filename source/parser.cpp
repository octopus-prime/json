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
//#include <boost/format.hpp>

//using namespace std::string_literals;
namespace qi = boost::spirit::qi;

namespace json {
namespace impl {

template <typename Iterator, typename Skipper>
class parser
:
	public qi::grammar<Iterator, Skipper, value_t()>
{
public:
	parser();

private:
	qi::rule<Iterator, Skipper, value_t()> _value;
	qi::symbols<char, null_t> _null;
	qi::rule<Iterator, Skipper, bool_t()> _boolean;
	qi::rule<Iterator, Skipper, number_t()> _number;
	qi::rule<Iterator, Skipper, string_t()> _string;
	qi::symbols<char, char> _special;
	qi::rule<Iterator, Skipper, array_t()> _array;
	qi::rule<Iterator, Skipper, object_t()> _object;
	qi::rule<Iterator, Skipper, std::pair<string_t,value_t>()> _pair;
};

template <typename Iterator, typename Skipper>
parser<Iterator, Skipper>::parser()
:
	parser::base_type(_value),
	_value(),//"value"s),
	_null(),//"null"s),
	_boolean(),//"boolean"s),
	_number(),//"number"s),
	_string(),//"string"s),
	_special(),
	_array(),//"array"s),
	_object(),//"object"s),
	_pair()//"pair"s)
{
	_value = _null | _boolean | _number | _string | _array | _object;
	_null.add("null", null_t());
	_boolean = qi::bool_;
	_number = qi::double_;
	_string = qi::lit('"') >> qi::no_skip[*(_special | (qi::char_ - (qi::lit('"') | qi::lit('\\'))))] >> qi::lit('"');
	_special.add("\\\"", '\"')("\\\\", '\\')("\\/", '/')("\\b", '\b')("\\f", '\f')("\\n", '\n')("\\r", '\r')("\\t", '\t'); // \u four-hex-digits
	_array = qi::lit('[') >> -(_value % qi::lit(',')) >> qi::lit(']');
	_object = qi::lit('{') >> -(_pair % qi::lit(',')) >> qi::lit('}');
	_pair = _string >> qi::lit(':') >> _value;
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

}

value_t
parse(const std::string& string)
{
	typedef std::string::const_iterator input_iterator;

	value_t value;
	input_iterator begin = string.begin();
	const input_iterator end = string.end();
	const impl::parser<input_iterator, qi::standard::space_type> parser;

//	try
//	{
		const bool success = qi::phrase_parse(begin, end, parser, qi::standard::space, value);
		if (!success || begin != end)
			throw impl::parser_exception();
//	}
//	catch(const qi::expectation_failure<input_iterator>& exception)
//	{
//		boost::format what("Expected %s but found \"%s\".");
//		what % exception.what_ % std::string(exception.first, exception.last);
//		throw std::runtime_error(what.str());
//	}

	return value;
}

}
