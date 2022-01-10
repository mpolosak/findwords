#include"process.hpp"
#include<fstream>
#include<iostream>
#include<regex>

using namespace std;

int processFile(const ProgramOptions &options){
    const auto& [filepath, length, regex_str] = options;
    fstream file(options.filepath);
    if(!file){
        cerr<<"Failed to open file '"<< filepath<<"'\n";
        return 1;
    }
    std::regex regex;
    try{
        regex = std::regex(regex_str);
    }
    catch(const regex_error &error){
        cerr<<"Incorrect regex format\n";
        return 1;
    }
    string word;
    while(file){
        file>>word;
        if((!length||word.length()==length)&&regex_match(word, regex))
            cout<<word<<"\n";
    }
    return 0;
}