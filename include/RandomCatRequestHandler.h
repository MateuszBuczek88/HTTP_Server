#ifndef INCLUDE_RANDOMCATREQUESTHANDLER_H_
#define INCLUDE_RANDOMCATREQUESTHANDLER_H_
#include <iostream>
#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Timestamp.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeFormat.h"
#include "Poco/Exception.h"
#include "Poco/ThreadPool.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"

using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPServer;
using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPRequestHandlerFactory;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Util::Application;
using Poco::Timestamp;
using Poco::DateTimeFormatter;

class RandomCatRequestHandler: public HTTPRequestHandler {
 public:
    RandomCatRequestHandler();
    void handleRequest(
        HTTPServerRequest& request,
        HTTPServerResponse& response);
};

#endif  // INCLUDE_RANDOMCATREQUESTHANDLER_H_
