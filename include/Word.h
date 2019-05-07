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

