/*
 * stringifier.cpp
 *
 *  Created on: 31.01.2015
 *      Author: mike_gresens
 */

#include <json/value.hpp>
#include <json/stringifier.hpp>
#include <unordered_map>
#include <sstream>
#include <iomanip>

namespace json {
namespace impl {

struct stringifier
{
	explicit stringifier(std::ostream& stream)
	:
		_stream{stream}
	{
	}

	void operator()(null_t const& value)
	{
		_stream << "null";
	}

	void operator()(bool_t const& value)
	{
		_stream << std::boolalpha << value;
	}

	void operator()(number_t const& value)
	{
		_stream << value;
	}

	void operator()(string_t const& value)
	{
		static std::unordered_map<char, std::string_view> const MAP
		{
			{'\"', "\\\""},
			{'\\', "\\\\"},
			{'/', "\\/"},
			{'\b', "\\b"},
			{'\f', "\\f"},
			{'\n', "\\n"},
			{'\r', "\\r"},
			{'\t', "\\t"}
		};
		_stream << '"';
		for (char const character : value)
		{
			auto const found = MAP.find(character);
			if (found == MAP.end())
				_stream << character;
			else
				_stream << found->second;
		}
		_stream << '"';
	}

	void operator()(array_t const& value)
	{
		_stream << '[';
		for (auto element = value.begin(); element != value.end(); ++element)
		{
			if (element != value.begin())
				_stream << ',';
			element->visit(*this);
		}
		_stream << ']';
	}

	void operator()(object_t const& value)
	{
		_stream << '{';
		for (auto element = value.begin(); element != value.end(); ++element)
		{
			if (element != value.begin())
				_stream << ',';
			(*this)(element->first);
			_stream << ':';
			element->second.visit(*this);
		}
		_stream << '}';
	}

private:
	std::ostream& _stream;
};

}

std::string stringify(const value_t& value)
{
	std::ostringstream stream;
	value.visit(impl::stringifier{stream});
	return stream.str();
}

}
