#include "ArgParser.h"
#include "version.h"
#include "ListLumpsCommand.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using namespace AutoVersion;

static ArgParser* parser;

static bool show_help = false;
static bool show_version = false;
static bool has_output = false;

static string output_filename = "";

static bool wadutil_cmdline_callback(CmdLineArgument* arg, const string& param);

int main(int argc, const char** argv)
{
    parser = new ArgParser(argc, argv);
    parser->setCallback(&wadutil_cmdline_callback);
    //Add command line arguments
    parser->addArgument("help", "Display the list of commands and arguments.", 'h', false, &show_help);
    parser->addArgument("version", "Show the version number and copyright information.", 'v', false, &show_version);
    parser->addArgument("output", "Specify the output filename for most commands", 'o', true, &has_output);

    if(parser->parse(false)) {
        if(show_version || show_help) {
            return 0;
        }
    } else {
        cout << "Error: mal-formatted command line arguments." << endl;
        parser->showHelp();
        return EXIT_FAILURE;
    }

    //Test command
    const vector<string>* args = parser->get_args();
    if(args->size() > 1 && args->at(0) == "list") {
        const string fname = args->at(1);
        ListLumpsCommand llc(fname);
        llc.run();
    }

    delete parser;
    return 0;
}

static bool
wadutil_cmdline_callback(CmdLineArgument* arg, const string& param)
{
    switch(arg->shortname) {
    case 'h':
        parser->showHelp();
        break;

    case 'v':
        cout << "wadutil version " << FULLVERSION_STRING << STATUS_SHORT << endl;
        cout << "Compiled on " << MONTH << '/' << DATE << '/' << YEAR << endl;
        cout << "Copyright (c) 2015-2016 Tosi" << endl;
        break;

    case 'o':
        output_filename = param;
        break;

    default:
        break;
    }
    return true;
}
