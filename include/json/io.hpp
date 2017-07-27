/*
 * io.hpp
 *
 *  Created on: 31.01.2015
 *      Author: mike_gresens
 */

#pragma once

#include <json/value.hpp>
#include <iostream>

namespace std {

ostream& operator<<(ostream& stream, json::value_t const& value);

}
