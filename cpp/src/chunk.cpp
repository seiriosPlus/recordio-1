//
// Created by tangwei12 on 2018/1/29.
//

#include <boost/crc.hpp>  // for boost::crc_32_type
#include <Buffer.h>
#include "chunk.h"
#include <header.h>


void Chunk::add(std::vector<char> &record) {
    this->records.push_back(record);
    this->numBytes += record.size();
}

void Chunk::dump(std::fstream& writer, int compressorIndex) {

    if (this->records.size() == 0) {
        return;
    }

    int nSize = this->records.size();

    Buffer data;

    for (int i = 0; i < nSize; ++i) {
        std::vector<char> record = this->records[i];
        const int record_size = record.size();

        char rs[4];
        strcpy(rs, std::to_string(record_size).c_str());
        data.write(rs);
        data.write(record);
    }

    Buffer compressed = compressData(data, compressorIndex);

    const char *compressed_ctr = compressed.to_str().c_str();
    int compressed_len = sizeof(compressed_ctr) / sizeof(compressed_ctr[0]);

    boost::crc_32_type  sum_crc;

    sum_crc.process_bytes(compressed_ctr, compressed_len);

    Header header;
    header.checkSum =  sum_crc.checksum();
    header.compressor = compressorIndex;
    header.compressedSize = compressed.len();
    header.numRecords = this->records.size();

    std::string header_str = write_header(&header);
    std::string compressed_str = compressed.to_str();

    writer.write(header_str.c_str(), header_str.size());
    writer.write(compressed_str.c_str(), compressed_str.size());

    this->records = std::vector<std::vector<char>>();
    this->numBytes = 0;
}

Buffer compressData(Buffer buf, int compressorIndex) {
    Buffer compressed;
    Compression compression = Compression(compressorIndex);
    return compressed;
}