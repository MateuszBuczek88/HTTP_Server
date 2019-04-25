#ifndef INCLUDE_TIMEREQUESTHANDLER_H_
#define INCLUDE_TIMEREQUESTHANDLER_H_
#include <iostream>
#include <string>
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Timestamp.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeFormat.h"
#include "Poco/Util/ServerApplication.h"


using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Util::Application;
using Poco::Timestamp;
using Poco::DateTimeFormatter;

class TimeRequestHandler: public HTTPRequestHandler {
 public:
    explicit TimeRequestHandler(const std::string& format);
    void handleRequest(
        HTTPServerRequest& request,
        HTTPServerResponse& response);

 private:
    std::string _format;
};

#endif  // INCLUDE_TIMEREQUESTHANDLER_H_
