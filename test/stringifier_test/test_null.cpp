/*
 * test_null.cpp
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

BOOST_AUTO_TEST_SUITE(test_null)

std::initializer_list<value_t> const values
{
	value_t {},
	null,
};

std::initializer_list<string_t> const strings
{
	"null",
	"null",
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
