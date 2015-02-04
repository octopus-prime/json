/*
 * test_object.cpp
 *
 *  Created on: 04.02.2015
 *      Author: mike_gresens
 */

#include "value_helper.hpp"
#include "../fixture/fixture_object.hpp"

namespace json {
namespace value_test {

typedef mpl::remove<all_types, object_t>::type other_types;

BOOST_FIXTURE_TEST_SUITE(test_value_object, fixture::fixture_object)

TEST_EQUAL_SAME_TYPE(_0.value, _1.value);
TEST_EQUAL_OTHER_TYPES(object_t, other_types);
//TEST_LESS_SAME_TYPE(objectean_false, objectean_true);
//TEST_LESS_OTHER_TYPES(objectean_t, other_types);
//TEST_HASH(objectean_false, objectean_true);
TEST_OUTPUT(_2.value, "{\n  \"2\": true,\n  \"1\": null\n}");	// not really predictable

BOOST_AUTO_TEST_SUITE_END()

}
}
