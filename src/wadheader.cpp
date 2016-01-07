#include "wadheader.h"
using std::istream;

WADHeader::WADHeader()
{
    //Make it a PWAD by default
    memcpy(&identification, "PWAD", sizeof(uint32_t));
    numlumps = 0;
    infotableofs = 0;
}

//Read in WAD header from an istream
WADHeader::WADHeader(istream& is)
{
    //Get identification
    is.read(reinterpret_cast<char*>(&identification), sizeof(uint32_t));
    //TODO: Handle endian-ness
    //Get number of lumps
    is.read(reinterpret_cast<char*>(&numlumps), sizeof(uint32_t));
    //Get infotable offset
    is.read(reinterpret_cast<char*>(&infotableofs), sizeof(uint32_t));
}
