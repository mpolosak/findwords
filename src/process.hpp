#pragma once
#include<string>
#include"program_options.hpp"
#include<regex>

int processFile(const ProgramOptions &options);
std::fstream openFileOrExit(const std::string &path);
std::regex createRegexOrExit(const std::string &regex_str);