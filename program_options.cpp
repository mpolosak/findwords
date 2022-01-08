#include"program_options.hpp"
#include<iostream>

po::options_description createOptionsDescription(std::string &file, int &length)
{
    po::options_description desc("Allowed options");

    desc.add_options()
        ("help,h", "show this description and return")
        ("file", po::value<std::string>(&file)->required(), "get names from file arg")
        ("length,l", po::value<int>(&length), "length of words");
        ;
    
    return desc;
}

void loadOptionsFromCommandline(int argc, char *argv[], std::string &file, int &length){
    auto desc = createOptionsDescription(file, length);
    po::positional_options_description pd;
    pd.add("file", 1);
    po::variables_map vm;
    try
    {
        po::store(po::command_line_parser(argc, argv).options(desc).positional(pd).run(), vm);
        po::notify(vm);
    }
    catch(std::logic_error &error)
    {
        std::cerr<<error.what()<<"\nType in 'findwords -h' to get help"<<std::endl;
        std::exit(1);
    }
    if(vm.count("help")){
        printHelpAndExit(desc);
    }
}

void printHelpAndExit(po::options_description &desc){
    std::cout<<desc<<std::endl;
    std::exit(0);
}