/*
 * test_array.cpp
 *
 *  Created on: 28.07.2017
 *      Author: mike
 */

#include <json/adapter.hpp>
#include <json/io.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

using test_t = std::vector<double>;

namespace std {

ostream& operator<<(ostream& stream, const test_t& array)
{
	copy(array.begin(), array.end(), ostream_iterator<double>(stream, ","));
	return stream;
}

}

namespace json {
namespace adapter_test {

BOOST_AUTO_TEST_SUITE(test_array)

std::initializer_list<value_t> const values
{
	array_t {},
	array_t {1.0},
	array_t {1.0, 2.0},
};

std::initializer_list<test_t> const arrays
{
	{},
	{1.0},
	{1.0, 2.0},
};

BOOST_DATA_TEST_CASE(test_values, values ^ arrays, value, expected)
{
	test_t array;
	BOOST_REQUIRE_NO_THROW(array = conversion::convert<test_t>(value));
	BOOST_CHECK_EQUAL(array, expected);
}

BOOST_DATA_TEST_CASE(test_arrays, arrays ^ values, array, expected)
{
	value_t value;
	BOOST_REQUIRE_NO_THROW(value = conversion::convert(array));
	BOOST_CHECK_EQUAL(value, expected);
}

BOOST_AUTO_TEST_SUITE_END()

}
}
