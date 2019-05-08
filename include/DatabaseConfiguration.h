#include <iostream>
#include <string>
#include "Poco/Util/LayeredConfiguration.h"
using Poco::Util::LayeredConfiguration;
using namespace std;


struct DatabaseConfiguration
{
    DatabaseConfiguration(const LayeredConfiguration & config);
    string host;
    int port ;
    string db ;
    string user ;
    string password ;
};

