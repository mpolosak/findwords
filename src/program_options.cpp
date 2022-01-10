#include"program_options.hpp"
#include<iostream>

using std::string;

po::options_description createOptionsDescription(ProgramOptions &options)
{
    po::options_description desc("Allowed options");

    desc.add_options()
        ("help,h", "show this description and return")
        ("file", po::value<string>(&options.filepath)->required(), "get names from file arg")
        ("length,l", po::value<uint>(&options.length)->default_value(0), "length of words, 0 means not to check length")
        ("regex,r", po::value<string>(&options.regex)->default_value(".*"), "regular expression to match words");
        ;
    
    return desc;
}

ProgramOptions loadOptionsFromCommandline(int argc, char *argv[]){
    ProgramOptions options;
    auto desc = createOptionsDescription(options);
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
        std::cerr<<error.what()<<"\nType in 'findwords -h' to get help\n";
        std::exit(1);
    }
    if(vm.count("help")){
        printHelpAndExit(desc);
    }
    return options;
}

void printHelpAndExit(po::options_description &desc){
    std::cout<<desc;
    std::exit(0);
}