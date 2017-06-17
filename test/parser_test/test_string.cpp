/*
 * test_string.cpp
 *
 *  Created on: 01.02.2015
 *      Author: mike_gresens
 */

#include <json/parser.hpp>
#include <json/io.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

namespace json {
namespace parser_test {

BOOST_AUTO_TEST_SUITE(test_string)

const std::initializer_list<string_t> strings
{
	"\"\"",
	"\"\"",
	"\"foo\"",
	"\" foo bar \"",
	"\"\\\"foo\\\"bar\\\"\"",
	"\"\\\\foo\\\\bar\\\\\"",
	"\"\\/foo\\/bar\\/\"",
	"\"\\bfoo\\bbar\\b\"",
	"\"\\ffoo\\fbar\\f\"",
	"\"\\nfoo\\nbar\\n\"",
	"\"\\rfoo\\rbar\\r\"",
	"\"\\tfoo\\tbar\\t\"",
	"\"\\u1234foo\\u5555bar\\u9876\"",
};

const std::initializer_list<value_t> values
{
	string_t {},
	string_t {""},
	string_t {"foo"},
	string_t {" foo bar "},
	string_t {"\"foo\"bar\""},
	string_t {"\\foo\\bar\\"},
	string_t {"/foo/bar/"},
	string_t {"\bfoo\bbar\b"},
	string_t {"\ffoo\fbar\f"},
	string_t {"\nfoo\nbar\n"},
	string_t {"\rfoo\rbar\r"},
	string_t {"\tfoo\tbar\t"},
	string_t {"\u1234foo\u5555bar\u9876"},
};

BOOST_DATA_TEST_CASE(test_success, strings ^ values, string, expected)
{
	value_t value;
	BOOST_REQUIRE_NO_THROW(value = parse(string));
	BOOST_CHECK_EQUAL(value, expected);
}

const std::initializer_list<string_t> invalids
{
	"\"\\ufoo\"",
	"\"\\u12\"",
	"\"\n\"",
	"\\",
	"\"foo",
};

BOOST_DATA_TEST_CASE(test_failure, invalids, string)
{
	BOOST_CHECK_THROW(parse(string), parser_exception);
}

BOOST_AUTO_TEST_SUITE_END()

}
}
