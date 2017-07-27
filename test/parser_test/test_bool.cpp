/*
 * test_bool.cpp
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

BOOST_AUTO_TEST_SUITE(test_bool)

std::initializer_list<string_t> const strings
{
	"false",
	"false",
	"true",
};

std::initializer_list<value_t> const values
{
	bool_t {},
	bool_t {false},
	bool_t {true},
};

BOOST_DATA_TEST_CASE(test_success, strings ^ values, string, expected)
{
	value_t value;
	BOOST_REQUIRE_NO_THROW(value = parse(string));
	BOOST_CHECK_EQUAL(value, expected);
}

std::initializer_list<string_t> const invalids
{
	"TRUE",
	"FALSE",
};

BOOST_DATA_TEST_CASE(test_failure, invalids, string)
{
	BOOST_CHECK_THROW(parse(string), parser_exception);
}

BOOST_AUTO_TEST_SUITE_END()

}
}
