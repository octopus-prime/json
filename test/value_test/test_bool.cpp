/*
 * test_bool.cpp
 *
 *  Created on: 03.02.2015
 *      Author: mike_gresens
 */

#include <json/value.hpp>
#include <json/io.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/lexical_cast.hpp>

namespace json {
namespace value_test {

BOOST_AUTO_TEST_SUITE(test_bool)

const std::initializer_list<value_t> values
{
	bool_t {},
	bool_t {false},
	bool_t {true},
};

const std::initializer_list<bool> equals
{
	true, true, false,
	true, true, false,
	false, false, true
};

BOOST_DATA_TEST_CASE(test_equal, values * values ^ equals, value1, value2, equal)
{
	BOOST_CHECK_EQUAL(value1 == value2, equal);
}

const std::initializer_list<value_t> others
{
	null_t {},
	number_t {},
	string_t {},
	array_t {},
	object_t {},
};

BOOST_DATA_TEST_CASE(test_not_equal, values * others, value1, value2)
{
	BOOST_CHECK_NE(value1, value2);
}

const std::initializer_list<string_t> strings
{
	"false",
	"false",
	"true",
};

BOOST_DATA_TEST_CASE(test_output, values ^ strings, value, string)
{
	BOOST_CHECK_EQUAL(boost::lexical_cast<string_t>(value), string);
}

BOOST_AUTO_TEST_SUITE_END()

}
}
