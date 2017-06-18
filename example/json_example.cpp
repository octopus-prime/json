/*
 * json_example.cpp
 *
 *  Created on: 31.01.2015
 *      Author: mike_gresens
 */

#include <json/json.hpp>
#include <algorithm>

using namespace std::string_literals;

static void
set_and_stringify()
{
	static const json::value_t value = json::object_t {
		{"firstName", "John"s},
		{"lastName", "Smith"s},
		{"isAlive", true},
		{"age", 25.0},
		{"height_cm", 167.6},
		{"address", json::object_t {
				{"streetAddress", "21 2nd Street"s},
				{"city", "New York"s},
				{"state", "NY"s},
				{"postalCode", "10021-3100"s}
			}
		},
		{"phoneNumbers", json::array_t {
				json::object_t {
					{"type", "home"s},
					{"number", "212 555-1234"s}
				},
				json::object_t {
					{"type", "office"s},
					{"number", "646 555-4567"s}
				}
			}
		},
		{"children", json::array_t {}},
		{"spouse", json::null}
	};

	std::cout << value << std::endl;

	std::cout << json::stringify(value) << std::endl;
}

static void
parse_and_get()
{
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

	static const auto printString = [](const json::value_t& value)
	{
		if (!value)
			return;
		const json::string_t& string = value.as<json::string_t>();
		std::cout << string << std::endl;
	};

	static const auto printNumber = [](const json::value_t& value)
	{
		if (!value)
			return;
		const json::number_t& number = value.as<json::number_t>();
		std::cout << number << std::endl;
	};

	static const auto printBool = [](const json::value_t& value)
	{
		if (!value)
			return;
		const json::bool_t& boolean = value.as<json::bool_t>();
		std::cout << std::boolalpha << boolean << std::endl;
	};

	static const auto printAddress = [](const json::value_t& value)
	{
		if (!value)
			return;
		const json::object_t& object = value.as<json::object_t>();
		printString(object.at("streetAddress"));
		printString(object.at("city"));
		printString(object.at("state"));
		printString(object.at("postalCode"));
	};

	static const auto printPhoneNumber = [](const json::value_t& value)
	{
		if (!value)
			return;
		const json::object_t& object = value.as<json::object_t>();
		printString(object.at("type"));
		printString(object.at("number"));
	};

	static const auto printPhoneNumbers = [](const json::value_t& value)
	{
		if (!value)
			return;
		const json::array_t& array = value.as<json::array_t>();
		std::for_each(array.begin(), array.end(), printPhoneNumber);
	};

	static const auto printObject = [](const json::value_t& value)
	{
		if (!value)
			return;
		const json::object_t& object = value.as<json::object_t>();
		printString(object.at("firstName"));
		printString(object.at("lastName"));
		printBool(object.at("isAlive"));
		printNumber(object.at("age"));
		printNumber(object.at("height_cm"));
		printAddress(object.at("address"));
		printPhoneNumbers(object.at("phoneNumbers"));
	};

	std::cout << string << std::endl;

	const json::value_t value = json::parse(string);

	std::cout << value << std::endl;

	printObject(value);
}

int
main()
{
	try
	{
		set_and_stringify();
		parse_and_get();
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
