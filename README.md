# json
JSON serialization for C++17

## Build

To build the library and run the tests use bjam.

```
bjam release -j16
```

## Example

Code

```
#include <json/value.hpp>
#include <json/stringifier.hpp>
#include <json/parser.hpp>
#include <json/io.hpp>
#include <json/adapter.hpp> // requires boost

struct Foo {
    std::string name;
    bool male;
};

JSON_ADAPT_STRUCT(Foo, name, male);

int main() {
    Foo const foo {"John Smith", true};

    auto const str = json::stringify(foo);  // std::string
    auto const bar = json::parse<Foo>(str); // same as foo
    auto const val = json::parse(str);      // json::value_t

    std::cout << "val = " << val << std::endl; // pretty
    std::cout << "str = " << str << std::endl; // compact

    auto const& name = val.as<json::object_t>().at("name").as<json::string_t>();
    auto const& male = val.as<json::object_t>().at("male").as<json::bool_t>();

    std::cout << "name = " << name << std::endl; // "John Smith"
    std::cout << "male = " << male << std::endl; // true

    return 0;
}
```

Output

```
val = {
  "male": true,
  "name": "John Smith"
}
str = {"male":true,"name":"John Smith"}
name = John Smith
male = true
```
