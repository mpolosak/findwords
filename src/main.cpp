#include<iostream>
#include<fstream>
#include"program_options.hpp"
#include"process.hpp"

using std::cout, std::string;

int main(int argc, char *argv[]){
    string path, regex;
    unsigned length;
    loadOptionsFromCommandline(argc, argv, path, length, regex);
    return processFile(path, length, regex);
}