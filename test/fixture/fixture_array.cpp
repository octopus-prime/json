/*
 * fixture_array.cpp
 *
 *  Created on: 04.02.2015
 *      Author: mike_gresens
 */

#include "fixture_array.hpp"

namespace json {
namespace fixture {

const fixture_base::entry_t
fixture_array::_0 =
{
	array_t {},
	"[]"
};

const fixture_base::entry_t
fixture_array::_1 =
{
	array_t {null},
	"[null]"
};

const fixture_base::entry_t
fixture_array::_2 =
{
	array_t {null, null},
	"[null,null]"
};

const string_t
fixture_array::_invalid1 =
{
	"[,null]"
};

const string_t
fixture_array::_invalid2 =
{
	"[null,]"
};

const string_t
fixture_array::_invalid3 =
{
	"[null}"
};

}
}
