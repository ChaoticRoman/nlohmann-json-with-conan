cmake_minimum_required(VERSION 3.15)
project(hello_json)

find_package(nlohmann_json REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} nlohmann_json::nlohmann_json)
