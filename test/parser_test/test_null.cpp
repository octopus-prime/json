/*
 * test_null.cpp
 *
 *  Created on: 01.02.2015
 *      Author: mike_gresens
 */

#include "../fixture/fixture_null.hpp"
#include "parser_helper.hpp"

namespace json {
namespace parser_test {

BOOST_FIXTURE_TEST_SUITE(test_parser_null, fixture::fixture_null)

TEST_PARSER_EQUAL(_null);

BOOST_AUTO_TEST_SUITE_END()

}
}
