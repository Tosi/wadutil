#ifndef WADLUMP_H
#define WADLUMP_H
#include <cstdint>
#include <istream>

class WADLump
{
    public:
        WADLump(std::istream& input);
        ~WADLump();

        bool load();
        void unload();
        char* get_data();

        const std::string& get_name() const { return name; }
        unsigned long get_lmpsize() const { return lmpsize; }

    protected:
    private:
        uint32_t filepos;
        uint32_t lmpsize;
        std::string name;
        std::istream& is;

        char* data;
};

#endif // WADLUMP_H
