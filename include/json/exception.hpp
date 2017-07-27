/*
 * exception.hpp
 *
 *  Created on: 31.01.2015
 *      Author: mike_gresens
 */

#pragma once

#include <exception>

namespace json {

class exception : public std::exception
{
protected:
	virtual ~exception() noexcept = default;
};

}
