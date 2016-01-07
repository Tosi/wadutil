#ifndef WADLUMP_H
#define WADLUMP_H
#include <cstdint>
#include <istream>

class WADLump
{
    public:
        WADLump(std::istream& is);
        ~WADLump();
        const std::string& get_name() const { return name; }

    protected:
    private:
        uint32_t filepos;
        uint32_t lmpsize;
        std::string name;

        char* data;
};

#endif // WADLUMP_H
