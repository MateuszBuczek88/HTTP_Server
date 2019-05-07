#ifndef INCLUDE_WORDSINDEXHANDLER_H_
#define INCLUDE_WORDSINDEXHANDLER_H_
#include <iostream>
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

class WordsIndexHandler: public HTTPRequestHandler {
 public:
    WordsIndexHandler();

    void handleRequest(
        HTTPServerRequest& request,
        HTTPServerResponse& response);
};

#endif  // INCLUDE_WORDSINDEXHANDLER_H_
