/*
 * test_array.cpp
 *
 *  Created on: 04.02.2015
 *      Author: mike_gresens
 */

#include <json/stringifier.hpp>
#include <json/io.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

namespace json {
namespace stringifier_test {

BOOST_AUTO_TEST_SUITE(test_array)

const std::initializer_list<value_t> values
{
	array_t {},
	array_t {null},
	array_t {null, null},
};

const std::initializer_list<string_t> strings
{
	"[]",
	"[null]",
	"[null,null]",
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
