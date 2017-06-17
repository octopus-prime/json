/*
 * value.hpp
 *
 *  Created on: 31.01.2015
 *      Author: mike_gresens
 */

#pragma once

#include <string>
#include <vector>
#include <map>
#include <variant>

namespace json {

class value_t;

using null_t = std::nullptr_t;
using bool_t = bool;
using number_t = double;
using string_t = std::string;
using array_t = std::vector<value_t>;
using object_t = std::map<string_t, value_t>;

inline constexpr null_t null {nullptr};

class value_t
{
public:
	value_t() noexcept
	:
		_variant{null}
	{
	}

	template <typename T>
	value_t(T const& value) noexcept
	:
		_variant{value}
	{
	}

	template <typename T>
	value_t(T&& value) noexcept
	:
		_variant{std::move(value)}
	{
	}

	value_t(value_t const& value) = default;
	value_t(value_t& value) = default;
	value_t(value_t&& value) = default;

	value_t& operator=(value_t const& value) = default;
	value_t& operator=(value_t&& value) = default;
//	:
//		_variant{std::move(value._variant)}
//	{
//	}

	template <typename T>
	bool is() const noexcept
	{
		return std::holds_alternative<T>(_variant);
	}

	template <typename T>
	T const& as() const
	{
		return std::get<T>(_variant);
	}

	auto visit(auto&& visitor) const
	{
		return std::visit(std::move(visitor), _variant);
	}

	bool operator==(value_t const& value) const
	{
		return _variant == value._variant;
	}

	bool operator<(value_t const& value) const
	{
		return _variant < value._variant;
	}

private:
	std::variant<null_t, bool_t, number_t, string_t, array_t, object_t> _variant;
};

}

//
//namespace json {
//
///**
// * Defines null type.
// */
//typedef boost::blank null_t;
//
///**
// * Defines boolean type.
// */
//typedef bool bool_t;
//
///**
// * Defines number type.
// */
//typedef double number_t;
//
///**
// * Defines string type.
// */
//typedef std::string string_t;
//
///**
// * Defines value type.
// */
//typedef boost::make_recursive_variant
//<
//	null_t,
//	bool_t,
//	number_t,
//	string_t,
//	std::vector<boost::recursive_variant_>,					// array_t
//	std::unordered_map<string_t, boost::recursive_variant_>	// object_t
//>::type value_t;
//
///**
// * Defines array type.
// */
//typedef std::vector<value_t> array_t;
//
///**
// * Defines object type.
// */
//typedef std::unordered_map<string_t, value_t> object_t;
//
///**
// * Constant null.
// */
//extern const value_t null;
//
//}
