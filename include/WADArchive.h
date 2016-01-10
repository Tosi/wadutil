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
        WADArchive(std::istream& is);
        ~WADArchive();

        const WADHeader* get_header() const { return header; }
        const WADDirectory* get_directory() const { return directory; }

    private:
        void readMetadata();

        WADHeader* header;
        WADDirectory* directory;
        std::ifstream* is;
};

#endif // WADARCHIVE_H
