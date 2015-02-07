/*
 * fixture_object.cpp
 *
 *  Created on: 04.02.2015
 *      Author: mike_gresens
 */

#include "fixture_object.hpp"

namespace json {
namespace fixture {

const fixture_base::entry_t
fixture_object::_0 =
{
	object_t {},
	"{}"
};

const fixture_base::entry_t
fixture_object::_1 =
{
	object_t {{"1", null}},
	"{\"1\":null}"
};

const fixture_base::entry_t
fixture_object::_2 =
{
	object_t {{"1", null}, {"2", true}},
	"{\"2\":true,\"1\":null}" // not really predictable
};

const string_t
fixture_object::_invalid1 =
{
	"{:null}"
};

const string_t
fixture_object::_invalid2 =
{
	"{null:null}"
};

const string_t
fixture_object::_invalid3 =
{
	"{\"foo\":}"
};

const string_t
fixture_object::_invalid4 =
{
	"{\"foo\":null,}"
};

const string_t
fixture_object::_invalid5 =
{
	"{,\"foo\":null}"
};

const string_t
fixture_object::_invalid6 =
{
	"{\"foo\":null]"
};

}
}
