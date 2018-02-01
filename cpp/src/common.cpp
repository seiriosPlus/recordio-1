//
// Created by tangwei12 on 2018/1/31.
//

#include <boost/lexical_cast.hpp>
#include "common.h"
#include <iostream>

char *convert_int_bytes(int num) {
    char bytes[4];
    bytes[3] = (num >> 24) & 0xFF;
    bytes[2] = (num >> 16) & 0xFF;
    bytes[1] = (num >> 8) & 0xFF;
    bytes[0] = num & 0xFF;
    return bytes;
}

std::string convert_int_string(int num) {
    char *bytes = convert_int_bytes(num);
    std::string str(bytes);
    return str;
}

int convert_string_int(std::string num_bytes) {
    const char *bytes = num_bytes.c_str();
    return (bytes[3] << 24) | (bytes[2] << 16) | (bytes[1] << 8) | (bytes[0]);
}

int convert_string_int(char* bytes) {
    return (bytes[3] << 24) | (bytes[2] << 16) | (bytes[1] << 8) | (bytes[0]);
}