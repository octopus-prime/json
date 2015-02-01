/*
 * parser_helper.hpp
 *
 *  Created on: 01.02.2015
 *      Author: mike_gresens
 */

#pragma once

#include <json/parser.hpp>
#include <json/io.hpp>
#include <boost/test/unit_test.hpp>

namespace json {
namespace parser_test {

#define TEST_PARSER_EQUAL(entry)\
BOOST_AUTO_TEST_CASE(test_parse##entry)\
{\
	value_t value;\
\
	BOOST_REQUIRE_NO_THROW\
	(\
		value = parse(entry.string);\
	);\
	BOOST_CHECK_EQUAL(value, entry.value);\
}\

}
}
