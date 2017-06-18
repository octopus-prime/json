/*
 * parser.cpp
 *
 *  Created on: 31.01.2015
 *      Author: mike_gresens
 */

#include <json/value.hpp>
#include <json/parser.hpp>
#include <boost/spirit/home/x3.hpp>
#include <boost/fusion/include/std_pair.hpp>
#include <sstream>

using namespace std::string_literals;

namespace x3 = boost::spirit::x3;

namespace json {
namespace impl {

auto const append8 = [](auto& ctx)
{
	char const character = x3::_attr(ctx);
	string_t& string = x3::_val(ctx);
	string.push_back(character);
};

auto const append32 = [](auto& ctx)
{
	char32_t const character = x3::_attr(ctx);
	string_t& string = x3::_val(ctx);
	*boost::utf8_output_iterator(std::back_inserter(string)) = character;
};

x3::rule<struct value, value_t> const value("value");
x3::rule<struct null, null_t> const null("null");
x3::rule<struct bool_, bool_t> const bool_("bool");
x3::rule<struct number, number_t> const number("number");
x3::rule<struct string, string_t> const string("string");
x3::rule<struct character, string_t> const character;
x3::rule<struct special, string_t> const special;
x3::rule<struct unicode, string_t> const unicode;
x3::rule<struct array, array_t> const array("array");
x3::rule<struct object, object_t> const object("object");
x3::rule<struct member, std::pair<string_t,value_t>> const member("member");

auto const value_def = null | bool_ | number | string | array | object;
auto const null_def = x3::symbols<null_t>{{"null", json::null}};
auto const bool__def = x3::bool_;
auto const number_def = x3::double_;
auto const string_def = x3::lexeme[x3::lit('"') >> *(special | unicode | character) >> x3::lit('"')];
auto const character_def = (x3::char_ - x3::lit('"') - x3::lit('\\') - x3::cntrl) [append8];
auto const special_def = x3::symbols<char>{{"\\\"", '\"'},{"\\\\", '\\'},{"\\/", '/'},{"\\b", '\b'},{"\\f", '\f'},{"\\n", '\n'},{"\\r", '\r'},{"\\t", '\t'}} [append8];
auto const unicode_def = (x3::lit("\\u") > x3::uint_parser<char32_t, 16, 4, 4>()) [append32];
auto const array_def = x3::lit('[') > -(value % x3::lit(',')) > x3::lit(']');
auto const object_def = x3::lit('{') > -(member % x3::lit(',')) > x3::lit('}');
auto const member_def = string > x3::lit(':') > value;

BOOST_SPIRIT_DEFINE(value, null, bool_, number, string, character, special, unicode, array, object, member);

class parser_exception
:
	public json::parser_exception, public std::runtime_error
{
public:
	explicit parser_exception(const std::string& what)
	:
		std::runtime_error(what)
	{
	}
};

}

value_t
parse(const std::string& string)
{
	typedef std::string::const_iterator input_iterator;

	value_t value;
	input_iterator begin = string.begin();
	const input_iterator end = string.end();

	try
	{
		const bool success = x3::phrase_parse(begin, end, impl::value, x3::space, value);
		if (!success || begin != end)
			throw impl::parser_exception("parse failed.");
	}
	catch (const x3::expectation_failure<input_iterator>& exception)
	{
		const size_t size = std::distance(exception.where(), end);
		const std::string_view view(&*exception.where(), std::min(size, 20UL));
		std::ostringstream stream;
		stream << "expected " << exception.which() << " but got " << '"' << view << '"';
		throw impl::parser_exception(stream.str());
	}

	return value;
}

}
