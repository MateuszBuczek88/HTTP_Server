#ifndef INCLUDE_HELLOWORLDREQUESTHANDLER_H_
#define INCLUDE_HELLOWORLDREQUESTHANDLER_H_
#include <iostream>
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Util/ServerApplication.h"

using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Util::Application;

class HelloWorldRequestHandler: public HTTPRequestHandler {
 public:
    HelloWorldRequestHandler();
    void handleRequest(
        HTTPServerRequest& request,
        HTTPServerResponse& response);
};

#endif  // INCLUDE_HELLOWORLDREQUESTHANDLER_H_
