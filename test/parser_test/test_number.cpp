/*
 * test_number.cpp
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

BOOST_AUTO_TEST_SUITE(test_number)

const std::initializer_list<string_t> strings
{
	"0",
	"0",
	"1",
	"3.14",
	"1e+100",
	"1e-100",
	"-1",
	"-3.14",
	"-1e+100",
	"-1e-100",
};

const std::initializer_list<value_t> values
{
	number_t {},
	number_t {0},
	number_t {1},
	number_t {3.14},
	number_t {1e+100},
	number_t {1e-100},
	number_t {-1},
	number_t {-3.14},
	number_t {-1e+100},
	number_t {-1e-100},
};

BOOST_DATA_TEST_CASE(test_success, strings ^ values, string, expected)
{
	value_t value;
	BOOST_REQUIRE_NO_THROW(value = parse(string));
	BOOST_CHECK_EQUAL(value, expected);
}

const std::initializer_list<string_t> invalids
{
	"0,0",
};

BOOST_DATA_TEST_CASE(test_failure, invalids, string)
{
	BOOST_CHECK_THROW(parse(string), parser_exception);
}

BOOST_AUTO_TEST_SUITE_END()

}
}
