#include "TimeRequestHandlerFactory.h"

TimeRequestHandlerFactory::TimeRequestHandlerFactory(const std::string& format):
    _format(format) {}

HTTPRequestHandler* TimeRequestHandlerFactory::createRequestHandler(
    const HTTPServerRequest& request) {

    if (request.getMethod() == "GET") {
        if (request.getURI() == "/")
            return new TimeRequestHandler (_format);
        else if (request.getURI() == "/hello")
            return new HelloWorldRequestHandler ();
        else if (request.getURI() == "/cat")
            return new RandomCatRequestHandler ();
        else
            return nullptr;
    } else {
        return nullptr;
    }
}
