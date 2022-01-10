#pragma once
#include<boost/program_options.hpp>

namespace po = boost::program_options;

struct ProgramOptions{
    std::string filepath;
    unsigned length;
    std::string regex;
};

po::options_description createOptionsDescription(ProgramOptions &options);
ProgramOptions loadOptionsFromCommandline(int argc, char *argv[]);
void printHelpAndExit(po::options_description &desc);
