#include <iostream>
#include "../lib/binaryio/read.h"
#include "../lib/binaryio/write.h"
#include "../lib/blob/types.h"
#include "../lib/blob/getset.h"
#include "../lib/blob/blob.h"
int main()
{
/*
    jp::blob blob;
    
    blob.set_id(1);
    blob.set_data(1.324);

    blob.write_binary("file.bin");
    blob.read_binary("file.bin");
*/

    jp::blobs blobs("file2.bin");


    jp::id_t i = 0;
    while(i < 255)
    {
        blobs.add(i,22.3);
        i++;
    }
    //blobs.add(1,21.3);
    


    return 0;
}