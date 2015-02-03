/*
 * stringifier.cpp
 *
 *  Created on: 31.01.2015
 *      Author: mike_gresens
 */

#include <json/value.hpp>
#include <json/stringifier.hpp>
#include <boost/spirit/include/karma.hpp>
#include <boost/fusion/include/std_pair.hpp>

namespace ka = boost::spirit::karma;

namespace json {
namespace impl {

template <typename Iterator>
class stringifier
:
	public ka::grammar<Iterator, value_t()>
{
public:
	stringifier();

private:
	ka::rule<Iterator, value_t()> _value;
	ka::symbols<null_t, char const*> _null;
	ka::rule<Iterator, bool_t()> _boolean;
	ka::rule<Iterator, number_t()> _number;
	ka::rule<Iterator, string_t()> _string;
	ka::symbols<char, char const*> _special;
	ka::rule<Iterator, array_t()> _array;
	ka::rule<Iterator, object_t()> _object;
	ka::rule<Iterator, std::pair<string_t,value_t>()> _pair;
};

template <typename Iterator>
stringifier<Iterator>::stringifier()
:
	stringifier::base_type(_value),
	_value(),
	_null(),
	_boolean(),
	_number(),
	_string(),
	_special(),
	_array(),
	_object(),
	_pair()
{
	_value = _null | _boolean | _number | _string | _array | _object;
	_null.add(null_t(), "null");
	_boolean = ka::bool_;
	_number = ka::double_;
	_string = ka::lit('"') << *(_special | ka::char_) << ka::lit('"');
	_special.add('\"', "\\\"")('\\', "\\\\")('/', "\\/")('\b', "\\b")('\f', "\\f")('\n', "\\n")('\r', "\\r")('\t', "\\t"); // \u four-hex-digits
	_array = ka::lit('[') << -(_value % ka::lit(',')) << ka::lit(']');
	_object = ka::lit('{') << -(_pair % ka::lit(',')) << ka::lit('}');
	_pair = _string << ka::lit(':') << _value;
}

class stringifier_exception
:
	public json::stringifier_exception
{
public:
	virtual const char* what() const noexcept;
};

const char*
stringifier_exception::what() const noexcept
{
	return "stringify failed.";
}

}

std::string
stringify(const value_t& value)
{
	typedef std::back_insert_iterator<std::string> output_iterator;

	std::string string;
	output_iterator inserter = std::back_inserter(string);
	const impl::stringifier<output_iterator> stringifier;

	const bool success = ka::generate(inserter, stringifier, value);
	if (!success)
		throw impl::stringifier_exception();

	return string;
}

}
