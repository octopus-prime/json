/*
 * test_string.cpp
 *
 *  Created on: 03.02.2015
 *      Author: mike_gresens
 */

#include "value_helper.hpp"
#include "../fixture/fixture_string.hpp"

namespace json {
namespace value_test {

typedef mpl::remove<all_types, string_t>::type other_types;

BOOST_FIXTURE_TEST_SUITE(test_value_string, fixture::fixture_string)

TEST_EQUAL_SAME_TYPE(_empty.value, _simple.value);
TEST_EQUAL_OTHER_TYPES(string_t, other_types);
//TEST_LESS_SAME_TYPE(stringean_false, stringean_true);
//TEST_LESS_OTHER_TYPES(stringean_t, other_types);
//TEST_HASH(stringean_false, stringean_true);
TEST_OUTPUT(_simple.value, "\"foo\"");

BOOST_AUTO_TEST_SUITE_END()

}
}
