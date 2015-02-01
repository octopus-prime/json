/*
 * stringifier.hpp
 *
 *  Created on: 31.01.2015
 *      Author: mike_gresens
 */

#pragma once

#include <json/value.hpp>
#include <json/exception.hpp>

namespace json {

/**
 * Defines stringifier exception.
 */
class stringifier_exception
:
	public exception
{
protected:
	virtual ~stringifier_exception() noexcept = default;
};

/**
 * Stringifies value.
 * @param value The value.
 * @return The string.
 * @throws stringifier_exception Failure while stringifying.
 */
std::string stringify(const value_t& value);

}
