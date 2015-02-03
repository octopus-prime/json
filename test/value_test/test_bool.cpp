/*
 * test_bool.cpp
 *
 *  Created on: 03.02.2015
 *      Author: mike_gresens
 */

#include "value_helper.hpp"
#include "../fixture/fixture_bool.hpp"

namespace json {
namespace value_test {

typedef mpl::remove<all_types, bool_t>::type other_types;

BOOST_FIXTURE_TEST_SUITE(test_value_bool, fixture::fixture_bool)

TEST_EQUAL_SAME_TYPE(_false.value, _true.value);
TEST_EQUAL_OTHER_TYPES(bool_t, other_types);
//TEST_LESS_SAME_TYPE(boolean_false, boolean_true);
//TEST_LESS_OTHER_TYPES(boolean_t, other_types);
//TEST_HASH(boolean_false, boolean_true);
TEST_OUTPUT(_true.value, "true");

BOOST_AUTO_TEST_SUITE_END()

}
}
