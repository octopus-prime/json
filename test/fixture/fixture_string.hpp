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
	static const entry_t _backslash;
	static const entry_t _slash;
	static const entry_t _backspace;
	static const entry_t _formfeed;
	static const entry_t _newline;
	static const entry_t _return;
	static const entry_t _tab;
	// \u four-hex-digits
};

}
}
