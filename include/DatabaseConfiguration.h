#ifndef INCLUDE_DATABASECONFIGURATION_H_
#define INCLUDE_DATABASECONFIGURATION_H_
#include <iostream>
#include <string>
#include <iomanip>
#include "Poco/Util/LayeredConfiguration.h"
using Poco::Util::LayeredConfiguration;
using namespace std;


struct DatabaseConfiguration {
    explicit DatabaseConfiguration(const LayeredConfiguration & config);
    string host;
    int port;
    string db;
    string user;
    string password;

    string toConfigString();
};
#endif  // INCLUDE_DATABASECONFIGURATION_H_
