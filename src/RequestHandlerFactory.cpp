#include "RequestHandlerFactory.h"

RequestHandlerFactory::RequestHandlerFactory(DatabaseConfiguration* _config):config(_config){
}

string RequestHandlerFactory::toConfigString() {
    stringstream result;
    result << "host="<< config->host << ";" <<"port=" <<config->port << ";" <<"db="<<config->db << ";"<<"user="<<config->user << ";"<<"password="<<config->password << ";";
    return result.str();
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
            else if (uri_segments[0] == "words")return new WordsRequestHandler(toConfigString());
            else
                return nullptr;

        } else if (uri_segments.size() == 2) return new WordRequestHandler(uri_segments,toConfigString());
    }
}
