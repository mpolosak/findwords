#include<iostream>
#include<fstream>
#include"program_options.hpp"
#include"process.hpp"

using std::cout, std::string;

int main(int argc, char *argv[]){
    const ProgramOptions options = loadOptionsFromCommandline(argc, argv);
    return processFile(options);
}