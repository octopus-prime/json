/*
 * fixture_bool.hpp
 *
 *  Created on: 31.01.2015
 *      Author: mgresens
 */

#pragma once

#include "fixture_base.hpp"

namespace json {
namespace fixture {

struct fixture_bool : fixture_base
{
	static const entry_t _true;
	static const entry_t _false;
};

}
}
