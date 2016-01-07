#include "ListLumpsCommand.h"
using std::string;

const string ListLumpsCommand::cmd_name = "list";
const string ListLumpsCommand::cmd_desc =
    "List the lumps in the given WAD or PK3 archive.";

ListLumpsCommand::ListLumpsCommand(const string& filename)
    : Command(filename)
{
}

bool ListLumpsCommand::run()
{
    //TODO: Implement
    return true;
}

ListLumpsCommand::~ListLumpsCommand()
{
    //dtor
}
