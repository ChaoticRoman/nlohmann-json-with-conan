#include <nlohmann/json.hpp>
#include <iostream>

int main() {
    // Use nlohmann::json namespace
    using json = nlohmann::json;

    // Create a JSON object
    json j;
    j["name"] = "John Doe";
    j["age"] = 30;
    j["is_student"] = false;
    j["skills"] = {"C++", "Python", "JavaScript"};

    std::cout << j << std::endl;

    if (j.type() == json::value_t::object) { // or .is_object()
        std::cout << "It is a object!" << std::endl;

        // Nasty, I would expect keys here...
        std::cout << "Values: " << std::endl;
        for (const auto &val: j) std::cout << val << ", ";
        std::cout << std::endl;

        std::cout << "Items are keys and values: " << std::endl;
        for (const auto &item: j.items()) {
            std::cout << item.key() << ": " << item.value() << "\n";
        }
    }

    json k {j, j, j};

    // docs: https://json.nlohmann.me/api/basic_json/type/
    std::cout << k << std::endl;
    std::cout << (k.type() == json::value_t::array ? "Array" : "Not array") << std::endl;
    std::cout << k[0]["name"] << std::endl;
    std::cout << k[0]["nonexistent"] << std::endl;  // We are getting null
    std::cout << (k[0]["nonexistent"].type() == json::value_t::null) << std::endl;  // We are getting 1

    // Serialize the JSON object to a string
    std::string serialized = j.dump(); // compact
    std::cout << serialized << std::endl;
    std::cout << j.dump(4) << std::endl; // pretty

    // Deserialize a JSON string to a JSON object
    json j2 = json::parse(R"({"name":"Jane Doe","age":25,"is_student":true})");
    std::cout << "Name: " << j2["name"] << ", Age: " << j2["age"] << std::endl;

    // More examples from https://json.nlohmann.me/api/basic_json/object/
    std::cout << json::object({ {"one", 1}, {"two", 2} }) << std::endl;

    return 0;
}
