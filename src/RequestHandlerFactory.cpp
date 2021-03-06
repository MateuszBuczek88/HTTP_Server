#include "RequestHandlerFactory.h"

RequestHandlerFactory::RequestHandlerFactory(const DatabaseConfiguration &_config):config(_config.toConnectionString()) {
}

HTTPRequestHandler* RequestHandlerFactory::createRequestHandler(
    const HTTPServerRequest& request) {

    std::vector<std::string> uri_segments;
    URI uri(request.getURI());
    uri.getPathSegments(uri_segments);

    if (request.getMethod() == "GET") {
        if (uri_segments.size() == 0) return nullptr;  // new IndexRequestHander ();
        else if (uri_segments.size() == 1) {
            if (uri_segments[0] == "word") return nullptr;
            else if (uri_segments[0] == "words")return new WordsRequestHandler(config);
            else
                return nullptr;

        } else if (uri_segments.size() == 2) return new WordRequestHandler(uri_segments, config);
    }
}
