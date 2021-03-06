#ifndef WADHEADER_H
#define WADHEADER_H

#include <cstdint>
#include <cstring>
#include <istream>

/**
 * Defines the header of a WAD file
 **/
class WADHeader
{
    public:
        WADHeader();
        WADHeader(std::istream& is);

        unsigned int get_identification() const {return identification;}
        unsigned int get_numlumps() const {return numlumps;}
        unsigned int get_infotableofs() const { return infotableofs;}

        bool is_PWAD() const {
            return memcmp(&identification, "PWAD", sizeof(uint32_t)) == 0;
        }

        bool is_IWAD() const {
            return memcmp(&identification, "IWAD", sizeof(uint32_t)) == 0;
        }

    private:
        uint32_t identification; // Either "IWAD" or "PWAD"
        uint32_t numlumps;       // Number of lumps in file
        uint32_t infotableofs;   // Byte offset to info table in file
        bool is_valid; //Whether the WAD file is valid or not
};
#endif // WADHEADER_H
