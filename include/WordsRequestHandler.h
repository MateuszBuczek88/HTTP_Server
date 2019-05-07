#ifndef INCLUDE_WORDSREQUESTHANDLER_H_
#define INCLUDE_WORDSREQUESTHANDLER_H_
#include <iostream>
#include <vector>
#include <iomanip>
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Data/MySQL/Connector.h"
#include "Poco/Data/Session.h"
#include "Poco/Data/Statement.h"


using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Util::Application;
using Poco::Data::MySQL::Connector;
using Poco::Data::Session;
using Poco::Data::Statement;
using namespace Poco::Data;

class WordsRequestHandler: public HTTPRequestHandler {
 public:
    WordsRequestHandler();

    void handleRequest(
        HTTPServerRequest& request,
        HTTPServerResponse& response);
    std::string idsToJSON (const std::vector<int>&ids);
};

#endif  // INCLUDE_WORDSREQUESTHANDLER_H_
