#ifndef INCLUDE_TIMEREQUESTHANDLERFACTORY_H_
#define INCLUDE_TIMEREQUESTHANDLERFACTORY_H_
#include <ctype.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Foundation.h"
#include "Poco/URI.h"
#include "WordRequestHandler.h"
#include "WordsRequestHandler.h"
#include "DatabaseConfiguration.h"


using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPRequestHandlerFactory;
using Poco::Net::HTTPServerRequest;
using Poco::URI;


class RequestHandlerFactory: public HTTPRequestHandlerFactory {
 public:
    explicit RequestHandlerFactory(DatabaseConfiguration* _config);
    HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request);
    string toConfigString();

 private:

    DatabaseConfiguration* config;
};

#endif  // INCLUDE_TIMEREQUESTHANDLERFACTORY_H_
