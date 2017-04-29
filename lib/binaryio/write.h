#pragma once
#include <string>
#include <ostream>
#include <fstream>
namespace jp{

struct binary_dump
{
    template<typename T>
    void write(std::ofstream& file, const T& data )
    {
        file.write(data, sizeof(data));
    }

};

template<>
void binary_dump::write(std::ofstream& file, const double& data )
{
    file.write(reinterpret_cast<const char*>(&data), sizeof(data));
}

template<>
void binary_dump::write(std::ofstream& file, const int& data )
{
    file.write(reinterpret_cast<const char*>(&data), sizeof(data));
}


}