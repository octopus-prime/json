/*
 * test_bool.cpp
 *
 *  Created on: 01.02.2015
 *      Author: mike_gresens
 */

#include "../fixture/fixture_bool.hpp"
#include "parser_helper.hpp"

namespace json {
namespace parser_test {

BOOST_FIXTURE_TEST_SUITE(test_parser_bool, fixture::fixture_bool)

TEST_PARSER_EQUAL(_true);
TEST_PARSER_EQUAL(_false);

BOOST_AUTO_TEST_SUITE_END()

}
}
