/*
 * adapter.hpp
 *
 *  Created on: 27.07.2017
 *      Author: mike
 */

#pragma once

#include <json/value.hpp>
#include <optional>
#include <boost/preprocessor/stringize.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/seq/for_each_i.hpp>
#include <boost/preprocessor/variadic/to_seq.hpp>

namespace json {

template <typename T>
inline T
get(value_t const& value);

template <typename T>
inline value_t
set(T const& value);

namespace detail {

template <typename T> struct is_value : std::false_type { };
template <> struct is_value<null_t> : std::true_type { };
template <> struct is_value<bool_t> : std::true_type { };
template <> struct is_value<number_t> : std::true_type { };
template <> struct is_value<string_t> : std::true_type { };

//template <typename T>
//using is_number = std::integral_constant<bool, std::is_convertible_v<T, double> && !std::is_same_v<T, bool>>;

template <typename T> struct is_optional : std::false_type { };
template <typename... Ts> struct is_optional<std::optional<Ts...> > : std::true_type { };

template <typename T> struct is_array : std::false_type { };
template <typename... Ts> struct is_array<std::vector<Ts...> > : std::true_type { };

template <typename T, typename = void>
struct converter {};

template <typename T>
struct converter<T, typename std::enable_if_t<is_value<T>::value>>
{
	static T const& from(value_t const& value)
	{
		return value.as<T>();
	}

	static value_t to(T const& value)
	{
		return value;
	}
};

template <typename T>
struct converter<T, typename std::enable_if_t<is_optional<T>::value>>
{
	static T from(value_t const& value)
	{
		return !value ? T {} : T {get<typename T::value_type>(value)};
	}

	static value_t to(T const& value)
	{
		return !value ? null : set(*value);
	}
};

template <typename T>
struct converter<T, typename std::enable_if_t<is_array<T>::value>>
{
	static T from(value_t const& value)
	{
		T array;
		for (auto const& element : value.as<array_t>())
			array.push_back(get<typename T::value_type>(element));
		return array;
	}

	static value_t to(T const& value)
	{
		array_t array;
		for (auto const& element : value)
			array.push_back(set(element));
		return array;
	}
};

}

template <typename T>
inline T
get(value_t const& value)
{
	return detail::converter<T>::from(value);
}

template <typename T>
inline value_t
set(T const& value)
{
	return detail::converter<T>::to(value);
}

}

#define JSON_ADAPT_STRUCT_GET(r, type, i, member) BOOST_PP_COMMA_IF(i) \
get<decltype(type::member)>(object.at(BOOST_PP_STRINGIZE(member)))

#define JSON_ADAPT_STRUCT_SET(r, type, i, member) BOOST_PP_COMMA_IF(i) \
{BOOST_PP_STRINGIZE(member), set(value.member)}

#define JSON_ADAPT_STRUCT_SEQ(STRUCT_NAME, SEQ) \
namespace json { \
template <> \
STRUCT_NAME \
get<STRUCT_NAME>(value_t const& value) \
{ \
	auto const& object = value.as<object_t>(); \
	return STRUCT_NAME \
	{ \
		BOOST_PP_SEQ_FOR_EACH_I(JSON_ADAPT_STRUCT_GET, STRUCT_NAME, SEQ) \
	}; \
}\
template <> \
value_t \
set(const STRUCT_NAME& value) \
{ \
	return object_t \
	{ \
		BOOST_PP_SEQ_FOR_EACH_I(JSON_ADAPT_STRUCT_SET, _, SEQ) \
	}; \
}\
}

#define JSON_ADAPT_STRUCT(...) \
JSON_ADAPT_STRUCT_SEQ(BOOST_PP_SEQ_HEAD(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__)), BOOST_PP_SEQ_TAIL(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__)))

#define JSON_HAS_ADAPTER
