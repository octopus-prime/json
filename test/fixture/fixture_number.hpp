/*
 * fixture_number.hpp
 *
 *  Created on: 31.01.2015
 *      Author: mgresens
 */

#pragma once

#include "fixture_base.hpp"

namespace json {
namespace fixture {

struct fixture_number : fixture_base
{
	static const entry_t _0;

	static const entry_t _1;
	static const entry_t _pi;
	static const entry_t _1e100;
	static const entry_t _1e_100;

	static const entry_t _m_1;
	static const entry_t _m_pi;
	static const entry_t _m_1e100;
	static const entry_t _m_1e_100;
};

}
}
