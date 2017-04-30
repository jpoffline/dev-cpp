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

    template<typename T>
    void write_cast(std::ofstream& file, const T& data )
    {
        file.write(reinterpret_cast<const char*>(&data), sizeof(data));
    }

};

template<>
void binary_dump::write(std::ofstream& file, const double& data )
{
    write_cast<double>(file, data);
}

template<>
void binary_dump::write(std::ofstream& file, const int& data )
{
    write_cast<int>(file, data);
}

template<>
void binary_dump::write(std::ofstream& file, const uint16_t& data )
{
    write_cast<uint16_t>(file, data);
}

template<>
void binary_dump::write(std::ofstream& file, const uint8_t& data )
{
    write_cast<uint8_t>(file, data);
}


}