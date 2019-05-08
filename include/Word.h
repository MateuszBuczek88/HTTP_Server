#ifndef INCLUDE_WORD_H_
#define INCLUDE_WORD_H_
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Word {
    int id;
    std::string polish;
    std::string english;
    string toJSON();
};
#endif  // INCLUDE_WORD_H_
