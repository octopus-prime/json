/*
 * test_number.cpp
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

BOOST_AUTO_TEST_SUITE(test_number)

std::initializer_list<value_t> const values
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

std::initializer_list<string_t> const strings
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

BOOST_DATA_TEST_CASE(test_success, values ^ strings, value, expected)
{
	string_t string;
	BOOST_REQUIRE_NO_THROW(string = stringify(value));
	BOOST_CHECK_EQUAL(string, expected);
}

BOOST_AUTO_TEST_SUITE_END()

}
}
