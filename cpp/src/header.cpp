//
// Created by tangwei12 on 2018/1/24.
//
#include <string>
#include <exception>
#include <iostream>

#include "../include/header.h"
#include <../include/common.h>

std::string write_header(const Header *header) {
    std::string head;

    std::string check = convert_int_string(header->checkSum);

    head.append(check);
    head.append(convert_int_string(header->compressor));
    head.append(convert_int_string(header->compressedSize));
    head.append(convert_int_string(header->numRecords));
    return head;
}


Header *parseHeader(std::string head) {
    int magicNumber = std::stoi(head.substr(0, 4));
    if (magicNumber != kMagicNumber) {
        throw "Failed to parse magic number";
    }

    Header he;
    he.checkSum = std::stoi(head.substr(4, 8));
    he.compressor = std::stoi(head.substr(8, 12));
    he.compressedSize = std::stoi(head.substr(12, 16));
    he.numRecords = std::stoi(head.substr(16, 20));
    return &he;
}