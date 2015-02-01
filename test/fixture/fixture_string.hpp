/*
 * fixture_string.hpp
 *
 *  Created on: 01.02.2015
 *      Author: mike_gresens
 */

#pragma once

#include "fixture_base.hpp"

namespace json {
namespace fixture {

struct fixture_string : fixture_base
{
	static const entry_t _empty;
	static const entry_t _simple;
	static const entry_t _space;
	static const entry_t _quote;
};

}
}
