/*
 * stringifier_helper.hpp
 *
 *  Created on: 01.02.2015
 *      Author: mike_gresens
 */

#pragma once

#include <json/stringifier.hpp>
#include <json/io.hpp>
#include <boost/test/unit_test.hpp>

namespace json {
namespace stringifier_test {

#define TEST_STRINGIFIER_EQUAL(entry)\
BOOST_AUTO_TEST_CASE(test_stringify##entry)\
{\
	string_t string;\
\
	BOOST_REQUIRE_NO_THROW\
	(\
		string = stringify(entry.value);\
	);\
	BOOST_CHECK_EQUAL(string, entry.string);\
}\

}
}
