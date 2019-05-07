#include <iostream>
#include <string>
#include "Poco/Util/LayeredConfiguration.h"
using Poco::Util::LayeredConfiguration;
using namespace std;


struct DatabaseConfiguration
{
    DatabaseConfiguration(const LayeredConfiguration & config);
    string host = "localhost";
    int port = 3306;
    string db = "word";
    string user = "root";
    string password = "mynewpassword";
};

