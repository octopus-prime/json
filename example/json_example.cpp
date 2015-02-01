/*
 * json_example.cpp
 *
 *  Created on: 31.01.2015
 *      Author: mike_gresens
 */

#include <json/json.hpp>

void set_and_stringify()
{
	json::value_t object = json::object_t {{"foo", true}};
	std::cout << boost::get<json::object_t>(object).at("foo") << std::endl;
}

static void
parse_and_get()
{
	// A demo string
	static const std::string string =
			"{\n"
			"  \"firstName\": \"John\",\n"
			"  \"lastName\": \"Smith\",\n"
			"  \"isAlive\": true,\n"
			"  \"age\": 25,\n"
			"  \"height_cm\": 167.6,\n"
			"  \"address\": {\n"
			"    \"streetAddress\": \"21 2nd Street\",\n"
			"    \"city\": \"New York\",\n"
			"    \"state\": \"NY\",\n"
			"    \"postalCode\": \"10021-3100\"\n"
			"  },\n"
			"  \"phoneNumbers\": [\n"
			"    {\n"
			"      \"type\": \"home\",\n"
			"      \"number\": \"212 555-1234\"\n"
			"    },\n"
			"    {\n"
			"      \"type\": \"office\",\n"
			"      \"number\": \"646 555-4567\"\n"
			"    }\n"
			"  ],\n"
			"  \"children\": [],\n"
			"  \"spouse\": null\n"
			"}\n";
/*
	static const auto printString = [](const json::value_t& value)
	{
		const json::string_t& string = boost::get<json::string_t>(value);
		std::cout << string << std::endl;
	};

	static const auto printNumber = [](const json::value_t& value)
	{
		const json::number_t& number = boost::get<json::number_t>(value);
		std::cout << number << std::endl;
	};

	static const auto printBool = [](const json::value_t& value)
	{
		const json::bool_t& boolean = boost::get<json::bool_t>(value);
		std::cout << std::boolalpha << boolean << std::endl;
	};

	static const auto printAddress = [](const json::value_t& value)
	{
		const json::object_t& object = boost::get<json::object_t>(value);
		printString(object.at("streetAddress"));
		printString(object.at("city"));
		printString(object.at("state"));
		printString(object.at("postalCode"));
	};

	static const auto printObject = [](const json::value_t& value)
	{
		const json::object_t& object = boost::get<json::object_t>(value);
		printString(object.at("firstName"));
		printString(object.at("lastName"));
		printBool(object.at("isAlive"));
		printNumber(object.at("age"));
		printNumber(object.at("height_cm"));
		printAddress(object.at("address"));
	};
*/
	// Print the string
	std::cout << string << std::endl;

	// Parse the string to value
	const json::value_t value = json::parse(string);

	std::cout << value << std::endl;

	// Print the value
//	printObject(value);
}

int main()
{
	try
	{
		parse_and_get();
/*
		const std::vector<json::value_t> values =
		{
			json::null,
			true,
			false,
			123.0,
			"foo",
			json::array_t {json::null, "blub"},
			json::object_t {{"foo", json::null}, {"bar", "blub"}}
		};

		for (const json::value_t& value : values)
		{
			const std::string string = json::stringify(value);
			std::cout << string << std::endl;

			const json::value_t value2 = json::parse(string);
			std::cout << (value == value2) << std::endl;
		}
*/
	}
	catch (const json::exception& exception)
	{
		std::cerr << "json error: " << exception.what() << std::endl;
	}
	catch (const std::exception& exception)
	{
		std::cerr << "std error: " << exception.what() << std::endl;
	}
	return EXIT_SUCCESS;
}
