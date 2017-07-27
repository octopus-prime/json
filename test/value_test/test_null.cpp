/*
 * test_null.cpp
 *
 *  Created on: 31.01.2015
 *      Author: mike_gresens
 */

#include <json/value.hpp>
#include <json/io.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/lexical_cast.hpp>

namespace json {
namespace value_test {

BOOST_AUTO_TEST_SUITE(test_null)

std::initializer_list<value_t> const values
{
	value_t {},
	null,
};

BOOST_DATA_TEST_CASE(test_equal, values * values, value1, value2)
{
	BOOST_CHECK_EQUAL(value1, value2);
}

std::initializer_list<value_t> const others
{
	bool_t {},
	number_t {},
	string_t {},
	array_t {},
	object_t {},
};

BOOST_DATA_TEST_CASE(test_not_equal, values * others, value1, value2)
{
	BOOST_CHECK_NE(value1, value2);
}

std::initializer_list<string_t> const strings
{
	"null",
	"null",
};

BOOST_DATA_TEST_CASE(test_output, values ^ strings, value, string)
{
	BOOST_CHECK_EQUAL(boost::lexical_cast<string_t>(value), string);
}

BOOST_AUTO_TEST_SUITE_END()

}
}
