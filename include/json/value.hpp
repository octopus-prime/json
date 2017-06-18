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

/**
 * Implements value type.
 */
class value_t;

/**
 * Defines null type.
 */
using null_t = std::nullptr_t;

/**
 * Defines boolean type.
 */
using bool_t = bool;

/**
 * Defines number type.
 */
using number_t = double;

/**
 * Defines string type.
 */
using string_t = std::string;

/**
 * Defines array type.
 */
using array_t = std::vector<value_t>;

/**
 * Defines object type.
 */
using object_t = std::map<string_t, value_t>;

/**
 * Constant null.
 */
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
	value_t(value_t& value) = default; // FIXME: WTF?!
	value_t(value_t&& value) = default;

	value_t& operator=(value_t const& value) = default;
	value_t& operator=(value_t&& value) = default;

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

	operator bool() const noexcept
	{
		return !is<null_t>();
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
