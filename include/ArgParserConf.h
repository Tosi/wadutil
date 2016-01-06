#ifndef ARGPARSERCONF_H
#define ARGPARSERCONF_H

#include <vector>
#include <string>

struct CmdLineArgument {
    std::string longname;
    std::string description;
    char shortname;
    bool has_argument;
    bool* flag; //If not NULL, will be set to true if the argument exists
};

class ArgParserConf
{
    public:
        ArgParserConf(){}
        ~ArgParserConf();
        void addArgument(const std::string& longname, const std::string& description, char shortname='\0', bool has_argument=false, bool* flag=nullptr);
        const std::vector<CmdLineArgument*>& getArguments() const { return arguments; }

    protected:
    private:
        std::vector<CmdLineArgument*> arguments;
};

#endif // ARGPARSERCONF_H
