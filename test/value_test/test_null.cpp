/*
 * test_null.cpp
 *
 *  Created on: 31.01.2015
 *      Author: mike_gresens
 */

#include "value_helper.hpp"
#include "../fixture/fixture_null.hpp"

namespace json {
namespace value_test {

typedef mpl::remove<all_types, null_t>::type other_types;

BOOST_FIXTURE_TEST_SUITE(test_value_null, fixture::fixture_null)

BOOST_AUTO_TEST_CASE(test_default_is_null)
{
	const value_t v1 = _default.value;
	const value_t v2 = _null.value;
	BOOST_CHECK_EQUAL(v1, v1);
	BOOST_CHECK_EQUAL(v1, v2);
	BOOST_CHECK_EQUAL(v2, v1);
}

BOOST_AUTO_TEST_CASE(test_equal_same_type)
{
	const value_t v1 = _null.value;
	const value_t v2 = _null.value;
	BOOST_CHECK_EQUAL(v1, v1);
	BOOST_CHECK_EQUAL(v1, v2);
	BOOST_CHECK_EQUAL(v2, v1);
}

TEST_EQUAL_OTHER_TYPES(null_t, other_types);
/*
BOOST_AUTO_TEST_CASE(test_less_same_type)
{
	const value_t v1 = null;
	const value_t v2 = null;
	BOOST_CHECK_EQUAL(less()(v1, v1), false);
	BOOST_CHECK_EQUAL(less()(v1, v2), false);
	BOOST_CHECK_EQUAL(less()(v2, v1), false);
}

TEST_LESS_OTHER_TYPES(null_t, other_types);

BOOST_AUTO_TEST_CASE(test_hash)
{
	const value_t v1 = null;
	const value_t v2 = null;
	BOOST_CHECK_EQUAL(hash()(v1), hash()(v1));
	BOOST_CHECK_EQUAL(hash()(v1), hash()(v2));
}
*/
TEST_OUTPUT(_null.value, "null");

BOOST_AUTO_TEST_SUITE_END()

}
}
