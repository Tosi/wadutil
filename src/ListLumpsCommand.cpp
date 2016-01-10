#include <string>
#include <map>
#include <iostream>

#include "ListLumpsCommand.h"
#include "WADArchive.h"

using std::map;
using std::string;
using std::istream;
using std::cout;
using std::endl;

const string ListLumpsCommand::cmd_name = "list";
const string ListLumpsCommand::cmd_desc =
    "List the lumps in the given WAD or PK3 archive.";

ListLumpsCommand::ListLumpsCommand(const string& filename)
    : Command(filename)
{
}

bool ListLumpsCommand::run()
{
    WADArchive archive(in_file);
    const WADDirectory* directory = archive.get_directory();
    const map<string, WADLump*>* lumps = directory->get_lumps();
    for(map<string, WADLump*>::const_iterator i = lumps->begin(); i != lumps->end(); i++) {
        cout << i->first << endl;
    }

    return true;
}

ListLumpsCommand::~ListLumpsCommand()
{
    //dtor
}
