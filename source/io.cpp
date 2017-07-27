/*
 * io.cpp
 *
 *  Created on: 31.01.2015
 *      Author: mike_gresens
 */

#include <json/io.hpp>

namespace json {
namespace impl {

class print_visitor
{
public:
	explicit print_visitor(std::ostream& stream)
	:
		_stream(stream),
		_indent(0)
	{
	}

	void operator()(const null_t& value)
	{
		_stream << "null";
	}

	void operator()(const bool_t& value)
	{
		_stream << std::boolalpha << value;
	}

	void operator()(const number_t& value)
	{
		_stream << value;
	}

	void operator()(const string_t& value)
	{
		_stream << '"' << value << '"';
	}

	void operator()(const array_t& value)
	{
		_stream << '[' << std::endl;
		_indent += 2;
		for (auto element = value.cbegin(); element != value.cend(); ++element)
		{
			_stream << std::string(_indent, ' ');
			element->visit(*this);
			if (element != value.cend() - 1)
				_stream << ',';
			_stream << std::endl;
		}
		_indent -= 2;
		_stream << std::string(_indent, ' ') << ']';
	}

	void operator()(const object_t& value)
	{
		_stream << '{' << std::endl;
		_indent += 2;
		for (auto member = value.cbegin(); member != value.cend(); ++member)
		{
			_stream << std::string(_indent, ' ');
			(*this)(member->first);
			_stream << ": ";
			member->second.visit(*this);
			auto next = member;
			if (++next != value.cend())
				_stream << ',';
			_stream << std::endl;
		}
		_indent -= 2;
		_stream << std::string(_indent, ' ') << '}';
	}

private:
	std::ostream& _stream;
	std::size_t _indent;
};

}
}

namespace std {

std::ostream&
operator<<(std::ostream& stream, const json::value_t& value)
{
	json::impl::print_visitor visitor(stream);
	value.visit(visitor);
	return stream;
}

}
