#pragma once
#include <string>
#include <ostream>
#include <fstream>
#include <vector>
#include "../binaryio/write.h"
#include "../binaryio/read.h"
#include "getset.h"
#include "types.h"

namespace jp{


class blob
{
    private:
        GetSet<id_t> _id;
        GetSet<data_t> _data;
        binary_dump out;
        binary_read read;



    public:
        blob(){};   
        blob(id_t in_id, data_t in_data) {_id.set(in_id); _data.set(in_data);}
        id_t id(){return _id.get();}
        data_t data(){return _data.get();}
        void set_id(id_t i){_id.set(i);}
        void set_data(data_t d){_data.set(d);}

        friend std::ostream& operator<<(std::ostream& os, blob& dt)
        {
            os << dt.id() << " " << dt.data() << "\n";
            return os;
        }   

        void write_binary(std::string fn)
        {
            std::ofstream fs(fn, std::ios::out | std::ios::binary);
            write_binary(fs);
            fs.close();
        }

        void read_binary(std::string fn)
        {
            std::ifstream fs(fn, std::ios::in | std::ios::binary);
            read_binary(fs);
            fs.close();
        }


        void write_binary(std::ofstream& fs)
        {
            _id.write(out, fs);
            _data.write(out, fs);
        }

        void read_binary(std::ifstream& fs)
        {
            _id.read(read, fs);
            _data.read(read, fs);
        }


};


class blobs
{
    private:
        std::string _filename;
        std::ofstream fs;
        void _open()
        {
            fs.open(_filename, std::ios::out | std::ios::binary);
        }
    public:
        blobs(std::string fn) 
        : _filename(fn)
        {
            _open();
        }
        blobs() 
        : _filename("default.bin")
        {
            _open();
        }
        void add(id_t id, data_t data)
        {
            blob b(id, data);
            b.write_binary(fs);
        }

        void seekid(id_t id)
        {
            
        }

        ~blobs(){fs.close();}
};


}