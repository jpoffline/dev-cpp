#pragma once
#include <string>
#include <ostream>
#include <fstream>
namespace jp{

struct binary_read
{
    template<typename T>
    void read(std::ifstream& file, T& data )
    {
        file.read(reinterpret_cast<char*>(&data), sizeof(T));
    }

};


}