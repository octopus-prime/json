/*
 * io.cpp
 *
 *  Created on: 31.01.2015
 *      Author: mike_gresens
 */

#include <json/json.hpp>

namespace json {
namespace impl {

class print_visitor
:
	public boost::static_visitor<>
{
public:
	print_visitor(std::ostream& stream);

	result_type operator()(const null_t& value);
	result_type operator()(const bool_t& value);
	result_type operator()(const number_t& value);
	result_type operator()(const string_t& value);
	result_type operator()(const array_t& value);
	result_type operator()(const object_t& value);

private:
	std::ostream& _stream;
	std::size_t _indent;
};

print_visitor::print_visitor(std::ostream& stream)
:
	boost::static_visitor<>(),
	_stream(stream),
	_indent(0)
{
}

print_visitor::result_type
print_visitor::operator()(const null_t& value)
{
	_stream << "null";
}

print_visitor::result_type
print_visitor::operator()(const bool_t& value)
{
	_stream << std::boolalpha << value;
}

print_visitor::result_type
print_visitor::operator()(const number_t& value)
{
	_stream << value;
}

print_visitor::result_type
print_visitor::operator()(const string_t& value)
{
	_stream << '"' << value << '"';
}

print_visitor::result_type
print_visitor::operator()(const array_t& value)
{
	_stream << '[' << std::endl;
	_indent += 2;
	for (auto element = value.cbegin(); element != value.cend(); ++element)
	{
		_stream << std::string(_indent, ' ');
		boost::apply_visitor(*this, *element);
		if (element != value.cend() - 1)
			_stream << ',';
		_stream << std::endl;
	}
	_indent -= 2;
	_stream << std::string(_indent, ' ') << ']';
}

print_visitor::result_type
print_visitor::operator()(const object_t& value)
{
	_stream << '{' << std::endl;
	_indent += 2;
	for (auto property = value.cbegin(); property != value.cend(); ++property)
	{
		_stream << std::string(_indent, ' ');
		(*this)(property->first);
		_stream << ": ";
		boost::apply_visitor(*this, property->second);
		auto next = property;
		if (++next != value.cend())
			_stream << ',';
		_stream << std::endl;
	}
	_indent -= 2;
	_stream << std::string(_indent, ' ') << '}';
}

}
}

namespace std {

std::ostream&
operator<<(std::ostream& stream, const json::value_t& value)
{
	json::impl::print_visitor visitor(stream);
	boost::apply_visitor(visitor, value);
	return stream;
}

}
