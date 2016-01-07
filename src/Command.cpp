#include "Command.h"
#include <fstream>
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;

Command::Command(const string& input_filename, const string& output_filename)
    : input(ifstream(input_filename, ios::in | ios::binary)),
      output(ofstream(output_filename, ios::out | ios::binary))
{
    has_input = false;
    has_output = false;
    if(input.is_open()) {
       has_input = true;
    }
    if(output.is_open()) {
        has_output = true;
    }
}

Command::~Command() {
    if(has_input) {
        input.close();
    }
    if(has_output) {
        output.close();
    }
}
