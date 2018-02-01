//
// Created by tangwei12 on 2018/1/29.
//

#ifndef CPP_WRITER_H
#define CPP_WRITER_H

#include <string>
#include "chunk.h"

const int defaultMaxChunkSize = 32 * 1024 * 1024;

struct Write {
    std::string writer;
    Chunk* chunk;
    int maxChunkSize;
    int compressor;
};

void NewWriter();

void Write();

void Close();

#endif //CPP_WRITER_H
