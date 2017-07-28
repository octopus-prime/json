# json
JSON serialization for C++17

## Build

To build the library and run the tests use bjam.

```
bjam release -j16
```

## Example
```
#include <json/value.hpp>
#include <json/stringifier.hpp>
#include <json/parser.hpp>
#include <json/io.hpp>
#include <json/adapter.hpp> // requires boost

struct Foo {
    std::string name;
    bool extend;
};

JSON_ADAPT_STRUCT(Foo, name, extend);

int main() {
    Foo const foo {"John Smith", true};

    auto const str = json::stringify(foo);  // std::string
    auto const bar = json::parse<Foo>(str); // same as foo
    auto const val = json::parse(str);      // json::value_t

    std::cout << "val = " << val << std::endl; // pretty
    std::cout << "str = " << str << std::endl; // compact

    return 0;
}
```
