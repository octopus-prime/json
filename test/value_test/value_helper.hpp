/*
 * value_helper.hpp
 *
 *  Created on: 31.01.2015
 *      Author: mike_gresens
 */

#pragma once

#include <json/value.hpp>
#include <json/io.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/remove.hpp>
#include <boost/lexical_cast.hpp>

namespace mpl = boost::mpl;

namespace json {
namespace value_test {

typedef mpl::vector
<
	null_t,
	bool_t,
	number_t,
	string_t,
	array_t,
	object_t
>::type all_types;

#define TEST_EQUAL_SAME_TYPE(value1, value2)\
BOOST_AUTO_TEST_CASE(test_equal_same_type)\
{\
	const value_t v1 = value1;\
	const value_t v2 = value2;\
	BOOST_CHECK_EQUAL(v1, v1);\
	BOOST_CHECK_NE(v1, v2);\
	BOOST_CHECK_NE(v2, v1);\
}

#define TEST_EQUAL_OTHER_TYPES(this_type, other_types)\
BOOST_AUTO_TEST_CASE_TEMPLATE(test_equal_other_type, other_type, other_types)\
{\
	const value_t v1 = this_type();\
	const value_t v2 = other_type();\
	BOOST_CHECK_NE(v1, v2);\
	BOOST_CHECK_NE(v2, v1);\
}
/*
#define TEST_LESS_SAME_TYPE(value1, value2)\
BOOST_AUTO_TEST_CASE(test_less_same_type)\
{\
	const value_t v1 = value1;\
	const value_t v2 = value2;\
	BOOST_CHECK_EQUAL(less()(v1, v1), false);\
	BOOST_CHECK_EQUAL(less()(v1, v2), true);\
	BOOST_CHECK_EQUAL(less()(v2, v1), false);\
}

#define TEST_LESS_OTHER_TYPES(this_type, other_types)\
BOOST_AUTO_TEST_CASE_TEMPLATE(test_less_other_type, other_type, other_types)\
{\
	const value_t v1 = this_type();\
	const value_t v2 = other_type();\
	BOOST_CHECK_EQUAL(less()(v1, v2), v1.which() < v2.which());\
	BOOST_CHECK_EQUAL(less()(v2, v1), v2.which() < v1.which());\
}

#define TEST_HASH(value1, value2)\
BOOST_AUTO_TEST_CASE(test_hash)\
{\
	const value_t v1 = value1;\
	const value_t v2 = value2;\
	BOOST_CHECK_NE(hash()(v1), hash()(v2));\
}
*/
#define TEST_OUTPUT(value, output)\
BOOST_AUTO_TEST_CASE(test_output)\
{\
	const value_t v = value;\
	BOOST_CHECK_EQUAL(boost::lexical_cast<std::string>(v), output);\
}

}
}
