/*
 * test_bool.cpp
 *
 *  Created on: 01.02.2015
 *      Author: mike_gresens
 */

#include "../fixture/fixture_bool.hpp"
#include "stringifier_helper.hpp"

namespace json {
namespace stringifier_test {

BOOST_FIXTURE_TEST_SUITE(test_stringifier_bool, fixture::fixture_bool)

TEST_STRINGIFIER_EQUAL(_true);
TEST_STRINGIFIER_EQUAL(_false);

BOOST_AUTO_TEST_SUITE_END()

}
}
