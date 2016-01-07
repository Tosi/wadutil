#ifndef LISTLUMPSCOMMAND_H
#define LISTLUMPSCOMMAND_H

#include "Command.h"


class ListLumpsCommand : public Command
{
    public:
        ListLumpsCommand(const std::string& filename);
        ~ListLumpsCommand();

        bool run();
        const std::string& get_name() const { return cmd_name; }
        const std::string& get_description() const { return cmd_desc; }

    protected:
    private:
        static const std::string cmd_name;
        static const std::string cmd_desc;
};

#endif // LISTLUMPSCOMMAND_H
