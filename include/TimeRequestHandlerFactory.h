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
#include "TimeRequestHandler.h"
#include "HelloWorldRequestHandler.h"
#include "RandomCatRequestHandler.h"
#include "MySQLRequestHandler.h"
#include "WordsIndexHandler.h"


using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPRequestHandlerFactory;
using Poco::Net::HTTPServerRequest;
using Poco::URI;


class TimeRequestHandlerFactory: public HTTPRequestHandlerFactory {
 public:
    explicit TimeRequestHandlerFactory(const std::string& format);
    HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request);
    bool is_number(const std::string& s);

 private:
    std::string _format;
};

#endif  // INCLUDE_TIMEREQUESTHANDLERFACTORY_H_
