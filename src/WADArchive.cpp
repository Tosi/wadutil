#include "WADArchive.h"
using std::ios_base;

WADArchive::WADArchive(const string& filename)
{
    is = ifstream(filename, ios_base::in | ios_base::binary);
    if(is.is_open()) {
        header = new WADHeader(is);
    } else {
        //TODO: Throw an exception or something
        header = nullptr;
    }
}

WADArchive::~WADArchive()
{
    delete header;
    if(is.is_open()) {
        is.close();
    }
}
