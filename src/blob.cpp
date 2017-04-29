#include <iostream>
#include "../lib/binaryio/read.h"
#include "../lib/binaryio/write.h"
#include "../lib/blob/types.h"
#include "../lib/blob/getset.h"
#include "../lib/blob/blob.h"
int main()
{

    jp::blob blob;
    
    blob.set_id(1);
    blob.set_data(1.324);

    blob.write_binary("file.bin");
    blob.read_binary("file.bin");
    return 0;
}