/*
 * test_string.cpp
 *
 *  Created on: 01.02.2015
 *      Author: mike_gresens
 */

#include "../fixture/fixture_string.hpp"
#include "parser_helper.hpp"

namespace json {
namespace parser_test {

BOOST_FIXTURE_TEST_SUITE(test_parser_string, fixture::fixture_string)

TEST_PARSER_EQUAL(_empty);
TEST_PARSER_EQUAL(_simple);
TEST_PARSER_EQUAL(_space);
TEST_PARSER_EQUAL(_quote);
TEST_PARSER_EQUAL(_backslash);
TEST_PARSER_EQUAL(_slash);
TEST_PARSER_EQUAL(_backspace);
TEST_PARSER_EQUAL(_formfeed);
TEST_PARSER_EQUAL(_newline);
TEST_PARSER_EQUAL(_return);
TEST_PARSER_EQUAL(_tab);
TEST_PARSER_EQUAL(_unicode);

TEST_PARSER_ERROR(_invalid1);
TEST_PARSER_ERROR(_invalid2);
TEST_PARSER_ERROR(_invalid3);
TEST_PARSER_ERROR(_invalid4);
TEST_PARSER_ERROR(_invalid5);

BOOST_AUTO_TEST_SUITE_END()

}
}
