#include "RequestHandlerFactory.h"

RequestHandlerFactory::RequestHandlerFactory(const std::string& format):
    _format(format) {}

HTTPRequestHandler* RequestHandlerFactory::createRequestHandler(
    const HTTPServerRequest& request) {

    std::vector<std::string> uri_segments;
    URI uri(request.getURI());
    uri.getPathSegments(uri_segments);

    if (request.getMethod() == "GET") {
        if (uri_segments.size() == 0) return nullptr;  // new IndexRequestHander ();
        else if (uri_segments.size() == 1) {
            if (uri_segments[0] == "time") return new TimeRequestHandler(_format);
            else if (uri_segments[0] == "cat") return new RandomCatRequestHandler();
            else if (uri_segments[0] == "hello") return new HelloWorldRequestHandler();
            else if (uri_segments[0] == "word") return new WordsIndexHandler();
            else if (uri_segments[0] == "words")return new WordsIndexHandler();
            else
                return nullptr;

        } else if (uri_segments.size() == 2) return new WordRequestHandler(uri_segments);
    }
}
