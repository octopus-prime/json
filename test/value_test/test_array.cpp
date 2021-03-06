/*
 * test_array.cpp
 *
 *  Created on: 04.02.2015
 *      Author: mike_gresens
 */

#include "value_helper.hpp"
#include "../fixture/fixture_array.hpp"

namespace json {
namespace value_test {

typedef mpl::remove<all_types, array_t>::type other_types;

BOOST_FIXTURE_TEST_SUITE(test_value_array, fixture::fixture_array)

TEST_EQUAL_SAME_TYPE(_0.value, _1.value);
TEST_EQUAL_OTHER_TYPES(array_t, other_types);
//TEST_LESS_SAME_TYPE(arrayean_false, arrayean_true);
//TEST_LESS_OTHER_TYPES(arrayean_t, other_types);
//TEST_HASH(arrayean_false, arrayean_true);
TEST_OUTPUT(_2.value, "[\n  null,\n  null\n]");

BOOST_AUTO_TEST_SUITE_END()

}
}
