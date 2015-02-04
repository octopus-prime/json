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
	string_t(" foo bar "),
	"\" foo bar \""
};

const fixture_base::entry_t
fixture_string::_quote =
{
	string_t("\"foo\"bar\""),
	"\"\\\"foo\\\"bar\\\"\""
};

const fixture_base::entry_t
fixture_string::_backslash =
{
	string_t("\\foo\\bar\\"),
	"\"\\\\foo\\\\bar\\\\\""
};

const fixture_base::entry_t
fixture_string::_slash =
{
	string_t("/foo/bar/"),
	"\"\\/foo\\/bar\\/\""
};

const fixture_base::entry_t
fixture_string::_backspace =
{
	string_t("\bfoo\bbar\b"),
	"\"\\bfoo\\bbar\\b\""
};

const fixture_base::entry_t
fixture_string::_formfeed =
{
	string_t("\ffoo\fbar\f"),
	"\"\\ffoo\\fbar\\f\""
};

const fixture_base::entry_t
fixture_string::_newline =
{
	string_t("\nfoo\nbar\n"),
	"\"\\nfoo\\nbar\\n\""
};

const fixture_base::entry_t
fixture_string::_return =
{
	string_t("\rfoo\rbar\r"),
	"\"\\rfoo\\rbar\\r\""
};

const fixture_base::entry_t
fixture_string::_tab =
{
	string_t("\tfoo\tbar\t"),
	"\"\\tfoo\\tbar\\t\""
};

}
}
