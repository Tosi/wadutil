#include "WADLump.h"
#include <string>
using std::istream;
using std::string;
using std::streamoff;

WADLump::WADLump(istream& input)
    : is(input)
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

//Load the lump data into memory
bool WADLump::load()
{
    if(data == nullptr) {
        data = new char[lmpsize];
        streamoff oldpos = is.tellg();
        is.seekg(filepos);
        is.read(data, lmpsize);
        is.seekg(oldpos);
    }

    return true;
}

//Unload the lump data from memory
void WADLump::unload()
{
    if(data) {
        delete data;
        data = nullptr;
    }
}

//Get the data of the lump
char* WADLump::get_data() {
    return load() ? data : nullptr;
}

WADLump::~WADLump()
{
    if(data) {
        delete data;
    }
}
