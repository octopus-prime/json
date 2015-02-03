/*
 * test_string.cpp
 *
 *  Created on: 01.02.2015
 *      Author: mike_gresens
 */

#include "../fixture/fixture_string.hpp"
#include "stringifier_helper.hpp"

namespace json {
namespace stringifier_test {

BOOST_FIXTURE_TEST_SUITE(test_stringifier_string, fixture::fixture_string)

TEST_STRINGIFIER_EQUAL(_empty);
TEST_STRINGIFIER_EQUAL(_simple);
TEST_STRINGIFIER_EQUAL(_space);
TEST_STRINGIFIER_EQUAL(_quote);
TEST_STRINGIFIER_EQUAL(_backslash);
TEST_STRINGIFIER_EQUAL(_slash);
TEST_STRINGIFIER_EQUAL(_backspace);
TEST_STRINGIFIER_EQUAL(_formfeed);
TEST_STRINGIFIER_EQUAL(_newline);
TEST_STRINGIFIER_EQUAL(_return);
TEST_STRINGIFIER_EQUAL(_tab);

/*
BOOST_AUTO_TEST_CASE(test_string_bad)
{
	BOOST_CHECK_THROW
	(
		parse(quote.string),
		json::parser_exception
	);
}
*/

BOOST_AUTO_TEST_SUITE_END()

}
}
