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

const fixture_base::entry_t
fixture_string::_backslash =
{
	string_t("foo\\bar"),
	"\"foo\\\\bar\""
};

const fixture_base::entry_t
fixture_string::_slash =
{
	string_t("foo/bar"),
	"\"foo\\/bar\""
};

const fixture_base::entry_t
fixture_string::_backspace =
{
	string_t("foo\bbar"),
	"\"foo\\bbar\""
};

const fixture_base::entry_t
fixture_string::_formfeed =
{
	string_t("foo\fbar"),
	"\"foo\\fbar\""
};

const fixture_base::entry_t
fixture_string::_newline =
{
	string_t("foo\nbar"),
	"\"foo\\nbar\""
};

const fixture_base::entry_t
fixture_string::_return =
{
	string_t("foo\rbar"),
	"\"foo\\rbar\""
};

const fixture_base::entry_t
fixture_string::_tab =
{
	string_t("foo\tbar"),
	"\"foo\\tbar\""
};

}
}
