#include<iostream>
#include<fstream>
#include"program_options.hpp"

using std::cout, std::string;

int main(int argc, char *argv[]){
    string path;
    int length;
    loadOptionsFromCommandline(argc, argv, path, length);
    return 0;
}