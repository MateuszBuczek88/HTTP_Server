#include "HelloWorldRequestHandler.h"

HelloWorldRequestHandler::HelloWorldRequestHandler() {}

void HelloWorldRequestHandler::handleRequest(
    HTTPServerRequest& request,
    HTTPServerResponse& response) {
        Application& app = Application::instance();

        app.logger().information(
        "Request from " + request.clientAddress().toString());

        response.setChunkedTransferEncoding(true);
        response.setContentType("text/html");

        std::ostream& ostr = response.send();
        ostr << "<html><head><title>HTTPTimeServer powered by POCO C++ Libraries</title>";
        ostr << "<meta http-equiv=\"refresh\" content=\"1\"></head>";
        ostr << "<body><p style=\"text-align: center; font-size: 48px;\">";
        ostr << "Hello World";
        ostr << "</p></body></html>";
    }
