/*
 * test_number.cpp
 *
 *  Created on: 01.02.2015
 *      Author: mike_gresens
 */

#include "../fixture/fixture_number.hpp"
#include "parser_helper.hpp"

namespace json {
namespace parser_test {

BOOST_FIXTURE_TEST_SUITE(test_parser_number, fixture::fixture_number)

TEST_PARSER_EQUAL(_0);
TEST_PARSER_EQUAL(_1);
TEST_PARSER_EQUAL(_pi);
TEST_PARSER_EQUAL(_1e100);
TEST_PARSER_EQUAL(_1e_100);
TEST_PARSER_EQUAL(_m_1);
TEST_PARSER_EQUAL(_m_pi);
TEST_PARSER_EQUAL(_m_1e100);
TEST_PARSER_EQUAL(_m_1e_100);

BOOST_AUTO_TEST_SUITE_END()

}
}
