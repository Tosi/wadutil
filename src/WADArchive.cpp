#include "WADArchive.h"
using std::ios;
using std::string;
using std::ifstream;
using std::istream;

WADArchive::WADArchive(const string& filename)
{
    header = nullptr;
    directory = nullptr;
    is = new ifstream(filename, ios::in | ios::binary);
    readMetadata();
}

void WADArchive::readMetadata()
{
    if(header) {
        delete header;
        header = nullptr;
    }
    if(directory) {
        delete directory;
        directory = nullptr;
    }

    if(is->is_open()) {
        is->seekg(0);
        header = new WADHeader(*is);
        directory  = new WADDirectory(*header, *is);
    } else {
        //TODO: Throw an exception or someothing
    }
}

WADArchive::~WADArchive()
{
    if(header)
        delete header;
    if(directory)
        delete directory;

    is->close();
    delete is;
}
