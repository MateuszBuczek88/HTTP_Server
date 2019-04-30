#ifndef INCLUDE_MYSQLREQUESTHANDLER_H_
#define INCLUDE_MYSQLREQUESTHANDLER_H_
#include <iostream>
#include <vector>
#include <string>
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Data/MySQL/Connector.h"
#include "Poco/Data/Session.h"
#include "Poco/Data/Statement.h"
#include "RequestHandlerFactory.h"

using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPResponse;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Util::Application;
using Poco::Data::MySQL::Connector;
using Poco::Data::Session;
using Poco::Data::Statement;
using namespace Poco::Data;
using namespace Poco::Net;

class WordRequestHandler: public HTTPRequestHandler {
 public:
    WordRequestHandler();
    explicit WordRequestHandler(std::vector<std::string>  _uri_seg);
    void handleRequest(
    HTTPServerRequest& request,
        HTTPServerResponse& response);
 private:
        std::vector<std::string>uri_seg;
        bool is_number(const std::string& s);
};

#endif  // INCLUDE_MYSQLREQUESTHANDLER_H_
