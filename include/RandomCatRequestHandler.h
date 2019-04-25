#ifndef INCLUDE_RANDOMCATREQUESTHANDLER_H_
#define INCLUDE_RANDOMCATREQUESTHANDLER_H_
#include <iostream>
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Timestamp.h"
#include "Poco/Util/ServerApplication.h"

using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Util::Application;
using Poco::Timestamp;

class RandomCatRequestHandler: public HTTPRequestHandler {
 public:
    RandomCatRequestHandler();
    void handleRequest(
        HTTPServerRequest& request,
        HTTPServerResponse& response);
};

#endif  // INCLUDE_RANDOMCATREQUESTHANDLER_H_
