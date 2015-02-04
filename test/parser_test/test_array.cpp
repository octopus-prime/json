/*
 * test_array.cpp
 *
 *  Created on: 04.02.2015
 *      Author: mike_gresens
 */

#include "../fixture/fixture_array.hpp"
#include "parser_helper.hpp"

namespace json {
namespace parser_test {

BOOST_FIXTURE_TEST_SUITE(test_parser_array, fixture::fixture_array)

TEST_PARSER_EQUAL(_0);
TEST_PARSER_EQUAL(_1);
TEST_PARSER_EQUAL(_2);

BOOST_AUTO_TEST_SUITE_END()

}
}
