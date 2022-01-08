cmake_minimum_required(VERSION 3.0)
project(findwords)

find_package(Boost COMPONENTS program_options REQUIRED)

add_executable(findwords main.cpp program_options.cpp process.cpp)

target_link_libraries(findwords Boost::program_options)