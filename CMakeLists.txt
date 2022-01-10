cmake_minimum_required(VERSION 3.0)
project(findwords)

find_package(Boost COMPONENTS program_options REQUIRED)

add_executable(findwords src/main.cpp src/program_options.cpp src/process.cpp)

target_link_libraries(findwords Boost::program_options)
target_compile_options(findwords PRIVATE -Wall -Wextra)