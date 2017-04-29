#pragma once
#include <string>
#include <ostream>
#include <fstream>
#include "../binaryio/write.h"
#include "../binaryio/read.h"


namespace jp{

template<typename T>
class GetSet
{
    private:
        T _data;
    public:
        GetSet(T d) : _data(d){}
        GetSet(){}
        T get(){return _data;}
        void set(T d){_data = d;}
        void write(binary_dump& dumper, std::ofstream& file)
        {
            std::cout << "WRITING: " << _data << std::endl;
            dumper.write<T>(file, _data);
        }
        void read(binary_read& reader, std::ifstream& file)
        {
            reader.read<T>(file, _data);
            std::cout << "READING: " << _data << std::endl;
        }
};

}