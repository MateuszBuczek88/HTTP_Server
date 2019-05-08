#ifndef INCLUDE_DATABASECONFIGURATION_H_
#define INCLUDE_DATABASECONFIGURATION_H_
#include <iostream>
#include <string>
#include <iomanip>
#include "Poco/Util/LayeredConfiguration.h"
using Poco::Util::LayeredConfiguration;

struct DatabaseConfiguration {
 private:
    std::string host;
    int port;
    std::string db;
    std::string user;
    std::string password;
 public:
    explicit DatabaseConfiguration(const LayeredConfiguration & config);
    std::string toConnectionString()const;
};
#endif  // INCLUDE_DATABASECONFIGURATION_H_
