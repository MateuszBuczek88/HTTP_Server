#include "RandomCatRequestHandler.h"

RandomCatRequestHandler::RandomCatRequestHandler() {}

void RandomCatRequestHandler::handleRequest(
    HTTPServerRequest& request,
    HTTPServerResponse& response) {
        Application& app = Application::instance();

        app.logger().information("Request from "
        + request.clientAddress().toString());

        Timestamp now;

        response.setChunkedTransferEncoding(true);
        response.setContentType("text/html");

        std::ostream& ostr = response.send();
        ostr << "<html><head><title>HTTPTimeServer powered by POCO C++ Libraries</title>";
        ostr << "<meta http-equiv=\"refresh\" content=\"2\"></head>";
        ostr << "<body><p style=\"text-align: center; font-size: 48px;\">";
        ostr << "My Work Is Done Here";
        ostr << "<br>";
        ostr << "<img src=https://cataas.com/cat?" << now.epochTime() << ">";
        ostr << "</body></html>";
    }
