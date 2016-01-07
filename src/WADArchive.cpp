#include "WADArchive.h"
using std::ios;
using std::string;
using std::ifstream;

WADArchive::WADArchive(const string& filename)
{
    header = nullptr;
    directory = nullptr;
    is = ifstream(filename, ios::in | ios::binary);
    if(is.is_open()) {
        header = new WADHeader(is);
        directory = new WADDirectory(*header, is);
    } else {
        //TODO: Throw an exception or something
        header = nullptr;
    }
}

WADArchive::~WADArchive()
{
    if(header)
        delete header;
    if(directory)
        delete directory;

    if(is.is_open()) {
        is.close();
    }
}
