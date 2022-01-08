#include"process.hpp"
#include<fstream>
#include<iostream>

using namespace std;

int processFile(const string &path, int length){
    fstream file(path);
    if(!file){
        cerr<<"Failed to open file '"<<path<<"'"<<endl;
        return 1;
    }
    string word;
    while(file){
        file>>word;
        if(!length||word.length()==length)
            cout<<word<<endl;
    }
    return 0;
}