/*
 * fixture_base.hpp
 *
 *  Created on: 01.02.2015
 *      Author: mike_gresens
 */

#pragma once

#include <json/value.hpp>

namespace json {
namespace fixture {

struct fixture_base
{
	struct entry_t
	{
		value_t value;
		string_t string;
	};
};

}
}
