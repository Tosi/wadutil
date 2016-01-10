#include "Command.h"
#include <fstream>
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;

Command::Command(const string& input_filename, const string& output_filename)
    : in_file(input_filename), out_file(output_filename)
{
    has_input = false;
    has_output = false;
    if(in_file != "") {
       has_input = true;
    }
    if(out_file != "") {
        has_output = true;
    }
}

Command::~Command() {
}
