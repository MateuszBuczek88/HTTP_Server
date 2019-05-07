

struct DatabaseConfiguration
{
    string host = "localhost";
    int port = 3306;
    string db="words";
    string user= "root";
    string password="mynewpassword";
    string compress="true";
    string auto-reconnect = "true";

    DatabaseConfiguration* createFromConfig(const LayeredConfiguration & config);

};

