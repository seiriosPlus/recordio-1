//
// Created by tangwei12 on 2018/1/29.
//

#ifndef CPP_CHUNK_H
#define CPP_CHUNK_H

#include <cstddef>
#include <vector>
#include <Buffer.h>
#include <iostream>
#include <fstream>

class Chunk {
private:
    std::vector<std::vector<char>> records;
    int numBytes;
public:
    void add(std::vector<char> &record);

    void dump(std::fstream& writer, int compressorIndex);
};

struct noopCompressor {

};


void Close();

Buffer compressData(Buffer buf, int compressorIndex);

void parseChunk();

void deflateData();


#endif //CPP_CHUNK_H
