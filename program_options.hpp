#pragma once
#include<boost/program_options.hpp>

namespace po = boost::program_options;

po::options_description createOptionsDescription(std::string &file, int &length);
void loadOptionsFromCommandline(int argc, char *argv[], std::string &file, int &length);
void printHelpAndExit(po::options_description &desc);