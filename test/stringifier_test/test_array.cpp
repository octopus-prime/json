/*
 * test_array.cpp
 *
 *  Created on: 04.02.2015
 *      Author: mike_gresens
 */

#include "../fixture/fixture_array.hpp"
#include "stringifier_helper.hpp"

namespace json {
namespace stringifier_test {

BOOST_FIXTURE_TEST_SUITE(test_stringifier_array, fixture::fixture_array)

TEST_STRINGIFIER_EQUAL(_0);
TEST_STRINGIFIER_EQUAL(_1);
TEST_STRINGIFIER_EQUAL(_2);

BOOST_AUTO_TEST_SUITE_END()

}
}
