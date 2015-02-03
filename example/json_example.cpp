/*
 * json_example.cpp
 *
 *  Created on: 31.01.2015
 *      Author: mike_gresens
 */

#include <json/json.hpp>

void set_and_stringify()
{
	static const json::value_t value = json::object_t {
		{"firstName", json::string_t("John")},
		{"lastName", json::string_t("Smith")},
		{"isAlive", json::bool_t(true)},
		{"age", json::number_t(25)},
		{"height_cm", json::number_t(167.6)},
		{"address", json::object_t {
				{"streetAddress", json::string_t("21 2nd Street")},
				{"city", json::string_t("New York")},
				{"state", json::string_t("NY")},
				{"postalCode", json::string_t("10021-3100")}
			}
		},
		{"phoneNumbers", json::array_t {
				json::object_t {
					{"type", json::string_t("home")},
					{"number", json::string_t("212 555-1234")}
				},
				json::object_t {
					{"type", json::string_t("office")},
					{"number", json::string_t("646 555-4567")}
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
		if (value == json::null)
			return;
		const json::string_t& string = boost::get<json::string_t>(value);
		std::cout << string << std::endl;
	};

	static const auto printNumber = [](const json::value_t& value)
	{
		if (value == json::null)
			return;
		const json::number_t& number = boost::get<json::number_t>(value);
		std::cout << number << std::endl;
	};

	static const auto printBool = [](const json::value_t& value)
	{
		if (value == json::null)
			return;
		const json::bool_t& boolean = boost::get<json::bool_t>(value);
		std::cout << std::boolalpha << boolean << std::endl;
	};

	static const auto printAddress = [](const json::value_t& value)
	{
		if (value == json::null)
			return;
		const json::object_t& object = boost::get<json::object_t>(value);
		printString(object.at("streetAddress"));
		printString(object.at("city"));
		printString(object.at("state"));
		printString(object.at("postalCode"));
	};

	static const auto printObject = [](const json::value_t& value)
	{
		if (value == json::null)
			return;
		const json::object_t& object = boost::get<json::object_t>(value);
		printString(object.at("firstName"));
		printString(object.at("lastName"));
		printBool(object.at("isAlive"));
		printNumber(object.at("age"));
		printNumber(object.at("height_cm"));
		printAddress(object.at("address"));
	};

	std::cout << string << std::endl;

	const json::value_t value = json::parse(string);

	std::cout << value << std::endl;

	printObject(value);
}

int main()
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
