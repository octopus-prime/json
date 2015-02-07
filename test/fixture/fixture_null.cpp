/*
 * fixture_null.cpp
 *
 *  Created on: 31.01.2015
 *      Author: mike_gresens
 */

#include "fixture_null.hpp"

namespace json {
namespace fixture {

const fixture_base::entry_t
fixture_null::_default =
{
	value_t(),
	"null"
};

const fixture_base::entry_t
fixture_null::_null =
{
	null_t(),
	"null"
};

const string_t
fixture_null::_empty =
{
	""
};

}
}
