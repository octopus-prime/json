/*
 * stringifier.hpp
 *
 *  Created on: 31.01.2015
 *      Author: mike_gresens
 */

#pragma once

#include <json/value.hpp>
#include <json/converter.hpp>
#include <json/exception.hpp>

namespace json {

class stringifier_exception : public exception
{
protected:
	virtual ~stringifier_exception() noexcept = default;
};

std::string stringify(value_t const& value);

template <typename Object>
std::string stringify(Object const& object)
{
	auto const value = conversion::convert(object);
	return stringify(value);
}

}
