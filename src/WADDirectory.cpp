#include "WADDirectory.h"
using std::map;
using std::string;
using std::pair;

WADDirectory::WADDirectory(WADHeader& header, std::istream& is)
{
    numlumps = header.get_numlumps();
    lumps = new map<string, WADLump*>();

    //Load lump information
    is.seekg(header.get_infotableofs());
    for(unsigned int i = 0; i < numlumps; i++) {
        WADLump* lump = new WADLump(is);
        lumps->insert(pair<const string, WADLump*>(lump->get_name(), lump));
    }
}

WADDirectory::~WADDirectory()
{
    for(map<string, WADLump*>::iterator i = lumps->begin(); i != lumps->end(); i++) {
        delete i->second;
    }

    delete lumps;
}

WADLump* WADDirectory::getLump(const string& name)
{
    map<string, WADLump*>::iterator e = lumps->find(name);
    if(e == lumps->end()) {
        return nullptr;
    }
    return e->second;
}
