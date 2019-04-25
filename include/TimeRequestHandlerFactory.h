#ifndef INCLUDE_TIMEREQUESTHANDLERFACTORY_H_
#define INCLUDE_TIMEREQUESTHANDLERFACTORY_H_
#include <iostream>
#include <string>
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
#include "TimeRequestHandler.h"
#include "HelloWorldRequestHandler.h"
#include "RandomCatRequestHandler.h"
#include "TimeRequestHandlerFactory.h"

using Poco::Net::ServerSocket;
using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPRequestHandlerFactory;
using Poco::Net::HTTPServer;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Net::HTTPServerParams;
using Poco::Timestamp;
using Poco::DateTimeFormatter;
using Poco::DateTimeFormat;
using Poco::ThreadPool;
using Poco::Util::ServerApplication;
using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::HelpFormatter;

class TimeRequestHandlerFactory: public HTTPRequestHandlerFactory {
 public:
    explicit TimeRequestHandlerFactory(const std::string& format);
    HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request);

 private:
    std::string _format;
};

#endif  // INCLUDE_TIMEREQUESTHANDLERFACTORY_H_
