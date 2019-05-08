#include "DatabaseConfiguration.h"

DatabaseConfiguration::DatabaseConfiguration(const LayeredConfiguration & config) {
    host = config.getString("MySQL.host" , "localhost");
    port = config.getInt("MySQL.port" , 3306);
    db = config.getString("MySQL.db" , "words");
    user = config.getString("MySQL.user" , "root");
    password = config.getString("MySQL.password" , "mynewpassword");
}

string DatabaseConfiguration::toConfigString() {
    stringstream result;
    result << "host=" << host << ";" << "port=" << port << ";" << "db=" << db << ";" << "user=" << user << ";" << "password=" << password;
    return result.str();
}
