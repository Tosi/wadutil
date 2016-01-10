#ifndef ARGPARSER_H
#define ARGPARSER_H
#include "ArgParserConf.h"

#include <vector>
#include <string>
#include <iostream>
#include <map>

typedef bool (*ArgParserCallback)(CmdLineArgument*, const std::string& param);

class ArgParser
{
    public:
        ArgParser(const int argc, const char** argv);
        virtual ~ArgParser();
        void addArgument(const std::string& longname, const std::string& description, char shortname='\0', bool has_argument=false, bool* flag=nullptr) {
            conf->addArgument(longname, description, shortname, has_argument, flag);
        }
        void setCallback(ArgParserCallback cbfn) { callback = cbfn; }
        bool parse(bool exit_on_unrecognized = false);
        void showHelp(std::ostream& os = std::cout);

        const std::vector<std::string>* get_args() const { return args; }

    protected:
        bool buildLookups();

    private:
        int argc;
        std::vector<std::string>* args;
        ArgParserConf* conf;
        ArgParserCallback callback;
        //Structures used to speed up lookups and make them easier
        CmdLineArgument* shortargs[256]; //For single character arguments
        std::map<std::string, CmdLineArgument*>* longargs;
};

#endif // ARGPARSER_H
