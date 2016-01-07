#include "WADLump.h"
#include <string>
using std::istream;
using std::string;

WADLump::WADLump(istream& is)
{
    //TODO: Handle endiannness
    //Get offset to lump in file
    is.read(reinterpret_cast<char*>(&filepos), sizeof(uint32_t));
    //Get size of lump in bytes
    is.read(reinterpret_cast<char*>(&lmpsize), sizeof(uint32_t));
    //Get name of lump
    char lmpname_tmp[9];
    is.read(&lmpname_tmp[0], 8);
    lmpname_tmp[8] = '\0'; //Ensure null-termination
    name = string(lmpname_tmp);

    data = nullptr;
}

WADLump::~WADLump()
{
    if(data) {
        delete data;
    }
}
