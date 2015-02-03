/*
 * test_number.cpp
 *
 *  Created on: 03.02.2015
 *      Author: mike_gresens
 */

#include "value_helper.hpp"
#include "../fixture/fixture_number.hpp"

namespace json {
namespace value_test {

typedef mpl::remove<all_types, number_t>::type other_types;

BOOST_FIXTURE_TEST_SUITE(test_value_number, fixture::fixture_number)

TEST_EQUAL_SAME_TYPE(_0.value, _1.value);
TEST_EQUAL_OTHER_TYPES(number_t, other_types);
//TEST_LESS_SAME_TYPE(numberean_false, numberean_true);
//TEST_LESS_OTHER_TYPES(numberean_t, other_types);
//TEST_HASH(numberean_false, numberean_true);
TEST_OUTPUT(_pi.value, "3.14");

BOOST_AUTO_TEST_SUITE_END()

}
}
