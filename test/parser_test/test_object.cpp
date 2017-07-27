/*
 * test_object.cpp
 *
 *  Created on: 04.02.2015
 *      Author: mike_gresens
 */

#include <json/parser.hpp>
#include <json/io.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

namespace json {
namespace parser_test {

BOOST_AUTO_TEST_SUITE(test_object)

std::initializer_list<string_t> const strings
{
	"{}",
	"{\"1\":null}",
	"{\"1\":null,\"2\":true}",
};

std::initializer_list<value_t> const values
{
	object_t {},
	object_t {{"1", null}},
	object_t {{"1", null}, {"2", true}},
};

BOOST_DATA_TEST_CASE(test_success, strings ^ values, string, expected)
{
	value_t value;
	BOOST_REQUIRE_NO_THROW(value = parse(string));
	BOOST_CHECK_EQUAL(value, expected);
}

std::initializer_list<string_t> const invalids
{
	"{:null}",
	"{null:null}",
	"{\"foo\":}",
	"{\"foo\":null,}",
	"{,\"foo\":null}",
	"{\"foo\":null]",
};

BOOST_DATA_TEST_CASE(test_failure, invalids, string)
{
	BOOST_CHECK_THROW(parse(string), parser_exception);
}

BOOST_AUTO_TEST_SUITE_END()

}
}
