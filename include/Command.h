#ifndef COMMAND_H
#define COMMAND_H
#include <string>
#include <fstream>

//Abstract base class representing a command that can be executed
//by the wadutil program.
class Command
{
    public:
        Command(const std::string& input_filename = "", const std::string& output_filename = "");
        ~Command();

        virtual bool run() = 0;
        virtual const std::string& get_name() const = 0;
        virtual const std::string& get_description() const = 0;

    protected:
        std::ifstream input;
        std::ofstream output;
        bool has_input;
        bool has_output;
    private:
};

#endif // COMMAND_H
