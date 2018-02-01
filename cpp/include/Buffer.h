//
// Created by tangwei12 on 2018/1/30.
//

#ifndef CPP_BUFFER_H
#define CPP_BUFFER_H

#include <vector>
#include <string>

class Buffer {
private:
    std::vector<char> buffer;
public:
    void write(std::vector<char> buf);
    void write(char *buf);
    void write(std::string str);
    std::string to_str();
    int len();
};


#endif //CPP_BUFFER_H
