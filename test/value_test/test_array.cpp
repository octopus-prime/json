/*
 * test_array.cpp
 *
 *  Created on: 04.02.2015
 *      Author: mike_gresens
 */

#include <json/value.hpp>
#include <json/io.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/lexical_cast.hpp>

namespace json {
namespace value_test {

BOOST_AUTO_TEST_SUITE(test_array)

std::initializer_list<value_t> const values
{
	array_t {},
	array_t {null},
	array_t {null, null},
};

std::initializer_list<bool> const equals
{
	true, false, false,
	false, true, false,
	false, false, true
};

BOOST_DATA_TEST_CASE(test_equal, values * values ^ equals, value1, value2, equal)
{
	BOOST_CHECK_EQUAL(value1 == value2, equal);
}

std::initializer_list<value_t> const others
{
	null_t {},
	bool_t {},
	number_t {},
	string_t {},
	object_t {},
};

BOOST_DATA_TEST_CASE(test_not_equal, values * others, value1, value2)
{
	BOOST_CHECK_NE(value1, value2);
}

std::initializer_list<string_t> const strings
{
	"[\n]",
	"[\n  null\n]",
	"[\n  null,\n  null\n]",
};

BOOST_DATA_TEST_CASE(test_output, values ^ strings, value, string)
{
	BOOST_CHECK_EQUAL(boost::lexical_cast<string_t>(value), string);
}

BOOST_AUTO_TEST_SUITE_END()

}
}
