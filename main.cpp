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

    // Serialize the JSON object to a string
    std::string serialized = j.dump();
    std::cout << serialized << std::endl;

    // Deserialize a JSON string to a JSON object
    json j2 = json::parse(R"({"name":"Jane Doe","age":25,"is_student":true})");
    std::cout << "Name: " << j2["name"] << ", Age: " << j2["age"] << std::endl;

    return 0;
}
