#include"process.hpp"
#include<fstream>
#include<iostream>
#include<regex>

using namespace std;

int processFile(const string &path, int length, const string &regex){
    fstream file(path);
    if(!file){
        cerr<<"Failed to open file '"<<path<<"'"<<endl;
        return 1;
    }
    std::regex std_regex;
    try{
        std_regex = std::regex(regex);
    }
    catch(regex_error error){
        cerr<<"Incorrect regex format"<<endl;
        return 1;
    }
    string word;
    while(file){
        file>>word;
        if((!length||word.length()==length)&&regex_match(word, std_regex))
            cout<<word<<endl;
    }
    return 0;
}