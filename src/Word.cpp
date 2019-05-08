#include "Word.h"
std::string Word::toJSON() {
    std::stringstream temp;
    temp << "{ \"id\" :" << id << ", \"polish\" :" << "\"" << polish << "\"" << ",\"english\" :" << "\"" << english << "\"" << "  }";
    return temp.str();
}

