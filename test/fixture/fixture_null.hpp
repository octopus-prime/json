/*
 * fixture_null.hpp
 *
 *  Created on: 31.01.2015
 *      Author: mgresens
 */

#pragma once

#include "fixture_base.hpp"

namespace json {
namespace fixture {

struct fixture_null : fixture_base
{
	static const entry_t _default;
	static const entry_t _null;
};

}
}
