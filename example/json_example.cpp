/*
 * json_example.cpp
 *
 *  Created on: 31.01.2015
 *      Author: mike_gresens
 */

#include <json/value.hpp>
#include <json/stringifier.hpp>
#include <json/parser.hpp>
#include <json/adapter.hpp>
#include <json/io.hpp>

namespace example {

struct Address
{
	std::string streetAddress;
	std::string city;
	std::string state;
	std::string postalCode;
};

struct PhoneNumber
{
	std::string type;
	std::string number;
};

struct Person
{
	std::string firstName;
	std::string lastName;
	bool isAlive;
	std::optional<double> age;
	double height_cm;
	Address address;
	std::vector<PhoneNumber> phoneNumbers;
	std::vector<Person> children;
};

}

JSON_ADAPT_STRUCT(example::Address, streetAddress, city, state, postalCode);
JSON_ADAPT_STRUCT(example::PhoneNumber, type, number);
JSON_ADAPT_STRUCT(example::Person, firstName, lastName, isAlive, age, height_cm, address, phoneNumbers, children);

static void
stringify()
{
	static example::Person const person
	{
		"John", "Smith",
		true,
		{},
		167.6,
		{"21 2nd Street", "New York", "NY", "10021-3100"},
		{
			{"home", "212 555-1234"},
			{"office", "646 555-4567"}
		},
		{}
	};

	std::cout << json::stringify(person) << std::endl;
}

static void
parse()
{
	static std::string const string =
		"{"
		"  \"firstName\": \"John\","
		"  \"lastName\": \"Smith\","
		"  \"isAlive\": true,"
		"  \"age\": null,"
		"  \"height_cm\": 167.6,"
		"  \"address\": {"
		"    \"streetAddress\": \"21 2nd Street\","
		"    \"city\": \"New York\","
		"    \"state\": \"NY\","
		"    \"postalCode\": \"10021-3100\""
		"  },"
		"  \"phoneNumbers\": ["
		"    {"
		"      \"type\": \"home\","
		"      \"number\": \"212 555-1234\""
		"    },"
		"    {"
		"      \"type\": \"office\","
		"      \"number\": \"646 555-4567\""
		"    }"
		"  ],"
		"  \"children\": []"
		"}";

	auto const person = json::parse<example::Person>(string);
	std::cout << person.firstName << ' ' << person.lastName << std::endl;
}

int
main()
{
	try
	{
		stringify();
		parse();
	}
	catch (json::exception const& exception)
	{
		std::cerr << "json error: " << exception.what() << std::endl;
	}
	catch (std::exception const& exception)
	{
		std::cerr << "std error: " << exception.what() << std::endl;
	}
	return EXIT_SUCCESS;
}
