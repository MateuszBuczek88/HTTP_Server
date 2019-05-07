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
            if (uri_segments[0] == "word") return nullptr;
            else if (uri_segments[0] == "words")return new WordsRequestHandler();
            else
                return nullptr;

        } else if (uri_segments.size() == 2) return new WordRequestHandler(uri_segments);
    }
}
