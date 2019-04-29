#include "TimeRequestHandlerFactory.h"

TimeRequestHandlerFactory::TimeRequestHandlerFactory(const std::string& format):
    _format(format) {}

bool TimeRequestHandlerFactory::is_number(const std::string& s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

HTTPRequestHandler* TimeRequestHandlerFactory::createRequestHandler(
    const HTTPServerRequest& request) {

    std::vector<std::string> uri_seg;
    URI u(request.getURI());
    u.getPathSegments(uri_seg);

    if (request.getMethod() == "GET") {
        if (uri_seg.size() == 0) return 0;  // new IndexRequestHander ();
        else if (uri_seg.size() == 1) {
            if (uri_seg[0] == "time") return new TimeRequestHandler(_format);
            else if (uri_seg[0] == "cat") return new RandomCatRequestHandler();
            else if (uri_seg[0] == "hello") return new HelloWorldRequestHandler();
            else if (uri_seg[0] == "word") return new WordsIndexHandler();
            else if (uri_seg[0] == "words")return new WordsIndexHandler();
            else
                return nullptr;

        } else if (uri_seg.size() == 2) {
            if (is_number(uri_seg[1])) return new MySQLRequestHandler(uri_seg);
            else
                return new WordsIndexHandler();
          }
    }
}
