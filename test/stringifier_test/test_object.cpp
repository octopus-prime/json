/*
 * test_object.cpp
 *
 *  Created on: 04.02.2015
 *      Author: mike_gresens
 */

#include "../fixture/fixture_object.hpp"
#include "stringifier_helper.hpp"

namespace json {
namespace stringifier_test {

BOOST_FIXTURE_TEST_SUITE(test_stringifier_object, fixture::fixture_object)

TEST_STRINGIFIER_EQUAL(_0);
TEST_STRINGIFIER_EQUAL(_1);
TEST_STRINGIFIER_EQUAL(_2);

BOOST_AUTO_TEST_SUITE_END()

}
}
