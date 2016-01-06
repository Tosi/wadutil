#include "ArgParserConf.h"
#include <iterator>
using std::vector;
using std::iterator;
using std::string;

ArgParserConf::~ArgParserConf()
{
    //Delete all allocated CmdLineArguments
    for(vector<CmdLineArgument*>::iterator it = arguments.begin(); it != arguments.end(); it++) {
            delete *it;
    }

    arguments.clear();
}

void ArgParserConf::addArgument(const string& longname, const string& description,
                                char shortname, bool has_argument, bool* flag) {
    CmdLineArgument* new_arg = new CmdLineArgument;
    new_arg->description = description;
    new_arg->longname = longname;
    new_arg->shortname = shortname;
    new_arg->has_argument = has_argument;
    new_arg->flag = flag;
    arguments.push_back(new_arg);
}
