#ifndef WADARCHIVE_H
#define WADARCHIVE_H

#include <string>
#include <istream>
#include <fstream>
#include "wadheader.h"
#include "WADDirectory.h"

class WADArchive
{
    public:
        WADArchive(const std::string& fname);
        ~WADArchive();
    private:
        WADHeader* header;
        WADDirectory* directory;
        std::ifstream is;
};

#endif // WADARCHIVE_H
