/*
 * value.hpp
 *
 *  Created on: 31.01.2015
 *      Author: mike_gresens
 */

#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <boost/blank.hpp>
#include <boost/variant.hpp>

namespace json {

/**
 * Defines null type.
 */
typedef boost::blank null_t;

/**
 * Defines boolean type.
 */
typedef bool bool_t;

/**
 * Defines number type.
 */
typedef double number_t;

/**
 * Defines string type.
 */
typedef std::string string_t;

/**
 * Defines value type.
 */
typedef boost::make_recursive_variant
<
	null_t,
	bool_t,
	number_t,
	string_t,
	std::vector<boost::recursive_variant_>,					// array_t
	std::unordered_map<string_t, boost::recursive_variant_>	// object_t
>::type value_t;

/**
 * Defines array type.
 */
typedef std::vector<value_t> array_t;

/**
 * Defines object type.
 */
typedef std::unordered_map<string_t, value_t> object_t;

/**
 * Constant null.
 */
extern const null_t null;

}
