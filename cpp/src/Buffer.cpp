//
// Created by tangwei12 on 2018/1/30.
//

#include "Buffer.h"


void Buffer::write(std::vector<char> buf_vector) {
    this->buffer.insert(this->buffer.end(), buf_vector.begin(), buf_vector.end());
}

void Buffer::write(char *buf) {
    std::vector<char> buf_vector(buf, buf + sizeof buf / sizeof buf[0]);
    this->write(buf_vector);
}

void Buffer::write(std::string str) {
    this->buffer.insert(this->buffer.end(), str.begin(), str.end());
}

std::string Buffer::to_str() {
    return std::string(this->buffer.begin(), this->buffer.end());
}

int Buffer::len() {
    return this->buffer.size();
}