//
// Created by tangwei12 on 2018/1/24.
//

#ifndef CPP_HEADER_H
#define CPP_HEADER_H

#include <vector>

const int kMagicNumber = 0x01020304;

enum Compression {
    NoCompression = 0,
    Snappy = 1,
    Gzip = 2
};

const int defaultCompressor = Snappy;

struct Header {
    unsigned int checkSum;
    unsigned int compressor;
    unsigned int compressedSize;
    unsigned int numRecords;
};


std::string write_header(const Header *header);

Header *parseHeader(std::string head);


#endif //CPP_HEADER_H
