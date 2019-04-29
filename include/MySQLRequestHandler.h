#ifndef INCLUDE_MYSQLREQUESTHANDLER_H_
#define INCLUDE_MYSQLREQUESTHANDLER_H_
#include <iostream>
#include <vector>
#include <string>
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Data/MySQL/Connector.h"
#include "Poco/Data/Session.h"
#include "Poco/Data/Statement.h"
#include "TimeRequestHandlerFactory.h"

using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Util::Application;
using Poco::Data::MySQL::Connector;
using Poco::Data::Session;
using Poco::Data::Statement;
using namespace Poco::Data;

class MySQLRequestHandler: public HTTPRequestHandler {
 public:
    MySQLRequestHandler();
    explicit MySQLRequestHandler(std::vector<std::string>  _uri_seg);
    void handleRequest(
    HTTPServerRequest& request,
        HTTPServerResponse& response);
 private:
        std::vector<std::string>uri_seg;
};

#endif  // INCLUDE_MYSQLREQUESTHANDLER_H_
