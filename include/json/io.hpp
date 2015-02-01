/*
 * io.hpp
 *
 *  Created on: 31.01.2015
 *      Author: mike_gresens
 */

#pragma once

#include <json/value.hpp>
#include <iostream>

/**
 * std
 */
namespace std {

/**
 * Output operator.
 * @param stream The stream.
 * @param value The value.
 * @return The stream.
 */
ostream&
operator<<(ostream& stream, const json::value_t& value);

}
