/*
 * fixture_number.cpp
 *
 *  Created on: 31.01.2015
 *      Author: mgresens
 */

#include "fixture_number.hpp"

namespace json {
namespace fixture {

const fixture_base::entry_t
fixture_number::_0 =
{
	number_t(0),
	"0.0"
};

const fixture_base::entry_t
fixture_number::_1 =
{
	number_t(1),
	"1.0"
};

const fixture_base::entry_t
fixture_number::_pi =
{
	number_t(3.14),
	"3.14"
};

const fixture_base::entry_t
fixture_number::_1e100 =
{
	number_t(1e100),
	"1.0e100"
};

const fixture_base::entry_t
fixture_number::_1e_100 =
{
	number_t(1e-100),
	"1.0e-100"
};

const fixture_base::entry_t
fixture_number::_m_1 =
{
	number_t(-1),
	"-1.0"
};

const fixture_base::entry_t
fixture_number::_m_pi =
{
	number_t(-3.14),
	"-3.14"
};

const fixture_base::entry_t
fixture_number::_m_1e100 =
{
	number_t(-1e100),
	"-1.0e100"
};

const fixture_base::entry_t
fixture_number::_m_1e_100 =
{
	number_t(-1e-100),
	"-1.0e-100"
};

}
}
