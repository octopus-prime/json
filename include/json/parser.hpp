/*
 * parser.hpp
 *
 *  Created on: 31.01.2015
 *      Author: mike_gresens
 */

#pragma once

#include <json/value.hpp>
#include <json/exception.hpp>

namespace json {

/**
 * Defines parser exception.
 */
class parser_exception
:
	public exception
{
protected:
	virtual ~parser_exception() noexcept = default;
};

/**
 * Parses string.
 * @param string The string.
 * @return The value.
 * @throws parser_exception Failure while parsing.
 */
value_t parse(const std::string& string);

}
