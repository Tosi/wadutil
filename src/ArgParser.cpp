#include "ArgParser.h"

#include <iostream>
#include <cstdlib>
using std::vector;
using std::string;
using std::map;
using std::pair;
using std::cout;
using std::endl;

ArgParser::ArgParser(const int argc, const char** argv)
{
    conf = new ArgParserConf();
    callback = nullptr;
    this->argc = argc;
    args = new vector<string>();
    //Convert to array of strings for easier handling
    for(int i = 1; i < argc; i++) {
            args->push_back(string(argv[i]));
    }
    //These structures will be built when parse is called
    for(int i = 0; i < 256; i++) {
        shortargs[i] = nullptr;
    }
    longargs = nullptr;
}

ArgParser::~ArgParser()
{
    delete conf;
    delete args;
    if(longargs) {
        delete longargs;
    }
}

//Build lookup table for short arguments and hash map for long arguments
bool ArgParser::buildLookups() {
    const std::vector<CmdLineArgument*>& opts = conf->getArguments();
    if(longargs != nullptr) {
        delete longargs;
        longargs = nullptr;
    }
    longargs = new map<string, CmdLineArgument*>();

    for(vector<CmdLineArgument*>::const_iterator i = opts.begin(); i != opts.end(); i++) {
            CmdLineArgument* arg = *i;
            if(arg->shortname != '\0') {
                shortargs[(unsigned int)arg->shortname] = arg;
            }
            longargs->insert(pair<string, CmdLineArgument*>(arg->longname, arg));
    }

    return true;
}

//Display help for the arguments in the current configuration
void ArgParser::showHelp(std::ostream& os)
{
    if(!conf)
        return;

    vector<CmdLineArgument*> opts = conf->getArguments();

    for(vector<CmdLineArgument*>::const_iterator i = opts.begin(); i != opts.end(); i++) {
        CmdLineArgument* arg = *i;
        string param =  arg->has_argument ? " [param]" : "";
        os << "--" << arg->longname << param;

        if(arg->shortname != '\0') {
            os << " \t-" << arg->shortname << param;
        }

        os << "\t\t" << arg->description << endl;
    }
}

//Parse the command line arguments, calling the callback function for each argument that exists
//If exit on unrecognized is true, will show the list of valid commands before exiting
bool ArgParser::parse(bool exit_on_unrecognized)
{
    if(!buildLookups()) {
        return false;
    }

    for(vector<string>::iterator i = args->begin(); i != args->end(); i++) {
        const string& arg = *i;
        bool has_argument = false;
        //Check for a short argument
        if(arg.length() == 2 && arg[0] == '-' && arg[1] != '-') {
            CmdLineArgument* opt = shortargs[(unsigned int)arg[1]];
            if(opt) {
                has_argument = true;
                //Set the flag if it was given to us
                if(opt->flag) {
                    *opt->flag = true;
                }
                //Call the callback if it is given
                if(callback) {
                    callback(opt, ""); //TODO: handle case of an argument
                }
            } else {
                cout << "Unrecognized argument: " << arg << endl;
                if(exit_on_unrecognized)
                    exit(EXIT_FAILURE);
            }
        } else if(arg.length() > 2 && arg[0] == '-' && arg[1] == '-') {
            //Lookup the long argument in the map (will be case sensitive)
            map<string, CmdLineArgument*>::const_iterator e
                                        = longargs->find(arg.substr(2));
            if(e != longargs->end()) {
                CmdLineArgument* opt = e->second;
                has_argument = true;
                if(opt->flag) {
                    *opt->flag = true;
                }
                if(callback) {
                    callback(opt, "");
                }
            } else {
                cout << "Unrecognized argument: " << arg << endl;
                if(exit_on_unrecognized)
                    exit(EXIT_FAILURE);
            }
        }

        //Remove the argument from the list if it was recognized
        if(has_argument) {
            i = args->erase(i);
            i--; //Since erase() returns an iterator after this one
        }
    }
    return true;
}
