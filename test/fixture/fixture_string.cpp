/*
 * fixture_string.cpp
 *
 *  Created on: 01.02.2015
 *      Author: mike_gresens
 */

#include "fixture_string.hpp"

namespace json {
namespace fixture {

const fixture_base::entry_t
fixture_string::_empty =
{
	string_t(),
	"\"\""
};

const fixture_base::entry_t
fixture_string::_simple =
{
	string_t("foo"),
	"\"foo\""
};

const fixture_base::entry_t
fixture_string::_space =
{
	string_t("foo bar"),
	"\"foo bar\""
};

const fixture_base::entry_t
fixture_string::_quote =
{
	string_t("foo\"bar"),
	"\"foo\\\"bar\""
};

}
}
