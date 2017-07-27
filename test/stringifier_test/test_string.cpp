/*
 * test_string.cpp
 *
 *  Created on: 01.02.2015
 *      Author: mike_gresens
 */

#include <json/stringifier.hpp>
#include <json/io.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

namespace json {
namespace stringifier_test {

BOOST_AUTO_TEST_SUITE(test_string)

std::initializer_list<value_t> const values
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
};

std::initializer_list<string_t> const strings
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
};

BOOST_DATA_TEST_CASE(test_success, values ^ strings, value, expected)
{
	string_t string;
	BOOST_REQUIRE_NO_THROW(string = stringify(value));
	BOOST_CHECK_EQUAL(string, expected);
}

BOOST_AUTO_TEST_SUITE_END()

}
}
