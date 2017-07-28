/*
 * adapter.hpp
 *
 *  Created on: 27.07.2017
 *      Author: mike
 */

#pragma once

#include <json/value.hpp>
#include <json/converter.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/seq/for_each_i.hpp>
#include <boost/preprocessor/variadic/to_seq.hpp>

#define JSON_ADAPT_STRUCT_GET(r, type, i, member) BOOST_PP_COMMA_IF(i) \
convert<decltype(type::member)>(object.at(BOOST_PP_STRINGIZE(member)))

#define JSON_ADAPT_STRUCT_SET(r, type, i, member) BOOST_PP_COMMA_IF(i) \
{BOOST_PP_STRINGIZE(member), convert(value.member)}

#define JSON_ADAPT_STRUCT_SEQ(STRUCT_NAME, SEQ) \
namespace json { \
namespace conversion { \
template <> \
STRUCT_NAME \
convert<STRUCT_NAME>(value_t const& value) \
{ \
	auto const& object = value.as<object_t>(); \
	return STRUCT_NAME \
	{ \
		BOOST_PP_SEQ_FOR_EACH_I(JSON_ADAPT_STRUCT_GET, STRUCT_NAME, SEQ) \
	}; \
}\
template <> \
value_t \
convert(const STRUCT_NAME& value) \
{ \
	return object_t \
	{ \
		BOOST_PP_SEQ_FOR_EACH_I(JSON_ADAPT_STRUCT_SET, _, SEQ) \
	}; \
}\
}\
}

#define JSON_ADAPT_STRUCT(...) \
JSON_ADAPT_STRUCT_SEQ(BOOST_PP_SEQ_HEAD(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__)), BOOST_PP_SEQ_TAIL(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__)))
