/*
 * fixture_bool.cpp
 *
 *  Created on: 31.01.2015
 *      Author: mgresens
 */

#include "fixture_bool.hpp"

namespace json {
namespace fixture {

const fixture_base::entry_t
fixture_bool::_true =
{
	bool_t(true),
	"true"
};

const fixture_base::entry_t
fixture_bool::_false =
{
	bool_t(false),
	"false"
};

}
}
