#include"process.hpp"
#include<fstream>
#include<iostream>

using namespace std;

int processFile(const ProgramOptions &options){
    const auto& [filepath, length, regex_str] = options;
    auto file = openFileOrExit(filepath);
    auto regex = createRegexOrExit(regex_str);
    string word;
    while(file){
        file>>word;
        if((!length||word.length()==length)&&regex_match(word, regex))
            cout<<word<<"\n";
    }
    return 0;
}

fstream openFileOrExit(const string &path){
    fstream file(path);
    if(!file){
        cerr<<"Failed to open file '"<< path<<"'\n";
        exit(1);
    }
    return file;
}

regex createRegexOrExit(const string &regex_str){
    try{
        return regex(regex_str);
    }
    catch(const regex_error &error){
        cerr<<"Incorrect regex format\n";
        exit(1);
    }
}