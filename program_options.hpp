#pragma once
#include<boost/program_options.hpp>

namespace po = boost::program_options;

po::options_description createOptionsDescription(std::string &file, int &length, std::string &regex);
void loadOptionsFromCommandline(int argc, char *argv[], std::string &file, int &length, std::string &regex);
void printHelpAndExit(po::options_description &desc);