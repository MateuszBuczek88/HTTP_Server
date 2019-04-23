#ifndef RANDOMCATREQUESTHANDLER_H
#define RANDOMCATREQUESTHANDLER_H
#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerParams.h"
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
#include <iostream>

using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPServer;
using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPRequestHandlerFactory;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Util::Application;
using Poco::Timestamp;
using Poco::DateTimeFormatter;
class RandomCatRequestHandler: public HTTPRequestHandler
	/// Return a HTML document with the current date and time.
{
public:
	RandomCatRequestHandler(const std::string& format):
		_format(format)
	{
	}

	void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
	{
		Application& app = Application::instance();
		app.logger().information("Request from " + request.clientAddress().toString());

		Timestamp now;
		std::string dt(DateTimeFormatter::format(now, _format));

		response.setChunkedTransferEncoding(true);
		response.setContentType("text/html");

		std::ostream& ostr = response.send();
		ostr << "<html><head><title>HTTPTimeServer powered by POCO C++ Libraries</title>";
        ostr <<	"<meta http-equiv=\"Pragma\" content=\"no-cache\">";
        ostr <<	"<meta http-equiv=\"Expires\" content=\"-1\">";
        ostr <<	"<meta http-equiv=\"CACHE-CONTROL\" content=\"NO-CACHE\">";
		ostr << "<meta http-equiv=\"refresh\" content=\"1\"></head>";
		ostr << "<body><p style=\"text-align: center; font-size: 48px;\">";
		ostr << "My Work Is Done Here";
		ostr << "<br>";
		ostr << "<img src=https://cataas.com/c>";
		ostr << "</body></html>";

	}

private:
	std::string _format;
};

#endif // RANDOMCATREQUESTHANDLER_H
