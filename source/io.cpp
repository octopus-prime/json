/*
 * io.cpp
 *
 *  Created on: 31.01.2015
 *      Author: mike_gresens
 */

#include <json/io.hpp>

namespace json {
namespace impl {

struct printer
{
	explicit printer(std::ostream& stream)
	:
		_stream(stream),
		_indent(0)
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
		_stream << '"' << value << '"';
	}

	void operator()(array_t const& value)
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

	void operator()(object_t const& value)
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

void print(std::ostream& stream, value_t const& value)
{
	value.visit(impl::printer{stream});
}

}

namespace std {

ostream& operator<<(ostream& stream, json::value_t const& value)
{
	json::print(stream, value);
	return stream;
}

}
