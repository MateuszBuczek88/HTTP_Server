#ifndef INCLUDE_TIMEREQUESTHANDLERFACTORY_H_
#define INCLUDE_TIMEREQUESTHANDLERFACTORY_H_
#include <iostream>
#include <string>
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "TimeRequestHandler.h"
#include "HelloWorldRequestHandler.h"
#include "RandomCatRequestHandler.h"

using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPRequestHandlerFactory;
using Poco::Net::HTTPServerRequest;

class TimeRequestHandlerFactory: public HTTPRequestHandlerFactory {
 public:
    explicit TimeRequestHandlerFactory(const std::string& format);
    HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request);

 private:
    std::string _format;
};

#endif  // INCLUDE_TIMEREQUESTHANDLERFACTORY_H_
