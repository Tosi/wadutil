#ifndef WADARCHIVE_H
#define WADARCHIVE_H

#include <string>
#include <istream>
#include <fstream>
#include "wadheader.h"

using std::string;
using std::ifstream;

class WADArchive
{
    public:
        WADArchive(const string& fname);
        ~WADArchive();
    private:
        WADHeader* header;
        ifstream is;
};

#endif // WADARCHIVE_H
