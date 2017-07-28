/*
 * parser.hpp
 *
 *  Created on: 31.01.2015
 *      Author: mike_gresens
 */

#pragma once

#include <json/value.hpp>
#include <json/converter.hpp>
#include <json/exception.hpp>

namespace json {

class parser_exception : public exception
{
protected:
	virtual ~parser_exception() noexcept = default;
};

value_t parse(std::string const& string);

template <typename Object>
Object parse(std::string const& string)
{
	auto const value = parse(string);
	return convert<Object>(value);
}

}
