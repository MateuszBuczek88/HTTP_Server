#ifndef INCLUDE_WORD_H_
#define INCLUDE_WORD_H_
#include <iostream>
#include <string>
#include <iomanip>

struct Word {
    int id;
    std::string polish;
    std::string english;
    std::string toJSON();
};
#endif  // INCLUDE_WORD_H_
