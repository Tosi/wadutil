#ifndef WADDIRECTORY_H
#define WADDIRECTORY_H

#include "WADHeader.h"
#include "WADLump.h"

#include <vector>
#include <istream>
#include <string>
#include <map>

class WADDirectory
{
    public:
        WADDirectory(WADHeader& header, std::istream& is);
        ~WADDirectory();
        WADLump* getLump(const std::string& name);
    protected:
    private:
        std::map<std::string, WADLump*>* lumps;
        unsigned long numlumps;
};

#endif // WADDIRECTORY_H
