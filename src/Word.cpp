#include "Word.h"
string Word::toJSON() {
    stringstream temp;
    temp << "{ \"id\" :" << id << ", \"polish\" :" << "\"" << polish << "\"" << ",\"english\" :" << "\"" << english << "\"" << "  }";
    return temp.str();
}

