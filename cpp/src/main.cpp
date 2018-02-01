#include <iostream>
#include <header.h>
#include <common.h>

int main() {
    std::cout << "Hello, World!" << std::endl;

//    Header header;
//    header.checkSum = 2014;
//    header.numRecords = 1000;
//    header.compressor = 1;
//    header.compressedSize = 2035;
//    std::string ret = write_header(&header);
//    int ret_i = convert_string_int(ret);

    int header = 2014;
    char *num_bytes = convert_int_bytes(header);
    int num = convert_string_int(num_bytes);

    int ret = 0;
    int ret_i = 1;

    std::cout << "ret: " << ret << std::endl;
    std::cout << "ret_i: " << ret_i << std::endl;
    return 0;
}