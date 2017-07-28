/*
 * converter.hpp
 *
 *  Created on: 28.07.2017
 *      Author: mike
 */

#pragma once

#include <json/value.hpp>
#include <optional>

namespace json {
namespace conversion {

template <typename T>
inline T
convert(value_t const& value);

template <typename T>
inline value_t
convert(T const& value);

namespace detail {

template <typename T, typename = void>
struct converter {};

template <typename T> struct is_value : std::false_type { };
template <> struct is_value<null_t> : std::true_type { };
template <> struct is_value<bool_t> : std::true_type { };
template <> struct is_value<number_t> : std::true_type { };
template <> struct is_value<string_t> : std::true_type { };

template <typename T>
struct converter<T, typename std::enable_if_t<is_value<T>::value>>
{
	static T const& convert(value_t const& value)
	{
		return value.as<T>();
	}

	static value_t convert(T const& value)
	{
		return value;
	}
};

template <typename T> struct is_optional : std::false_type { };
template <typename... Ts> struct is_optional<std::optional<Ts...> > : std::true_type { };

template <typename T>
struct converter<T, typename std::enable_if_t<is_optional<T>::value>>
{
	static T convert(value_t const& value)
	{
		return !value ? T {} : T {conversion::convert<typename T::value_type>(value)};
	}

	static value_t convert(T const& value)
	{
		return !value ? null : conversion::convert(*value);
	}
};

template <typename T> struct is_array : std::false_type { };
template <typename... Ts> struct is_array<std::vector<Ts...> > : std::true_type { };

template <typename T>
struct converter<T, typename std::enable_if_t<is_array<T>::value>>
{
	static T convert(value_t const& value)
	{
		T array;
		for (auto const& element : value.as<array_t>())
			array.push_back(conversion::convert<typename T::value_type>(element));
		return array;
	}

	static value_t convert(T const& value)
	{
		array_t array;
		for (auto const& element : value)
			array.push_back(conversion::convert(element));
		return array;
	}
};

}

template <typename T>
inline T
convert(value_t const& value)
{
	return detail::converter<T>::convert(value);
}

template <typename T>
inline value_t
convert(T const& value)
{
	return detail::converter<T>::convert(value);
}

}
}
