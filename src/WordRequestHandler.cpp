#include "WordRequestHandler.h"
using namespace std;

bool WordRequestHandler::is_number(const std::string& s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

WordRequestHandler::WordRequestHandler(const std::vector<std::string> &_uri_seg,  std::string _connection):uri_seg(_uri_seg),connection(_connection) {}

void WordRequestHandler::handleRequest(
    HTTPServerRequest& request,
    HTTPServerResponse& response) {

    if (!is_number(uri_seg[1])) {
        response.setStatus(HTTPResponse::HTTPStatus::HTTP_NOT_ACCEPTABLE);
        std::ostream& ostr = response.send();
        ostr << "Argument should be unsigned number!";
        return;
    }

    Application& app = Application::instance();

    app.logger().information(
    "Request from " + request.clientAddress().toString());

    response.setChunkedTransferEncoding(true);
    response.setContentType("application/json");
    Word row;
    Poco::Data::MySQL::Connector::registerConnector();
   // std:: string connection_string = "host=localhost;port=3306;db=words;user=root;password=mynewpassword;compress=true;auto-reconnect=true";

    Session session("MySQL", connection);
    Statement select(session);

    select << "SELECT id, polish, english FROM polish_english WHERE id="+uri_seg[1],
    into(row.id),
    into(row.polish),
    into(row.english),
    range(0 , 1);

    std::ostream& ostr = response.send();

    std::size_t items_count = select.execute();
    if (items_count == 1) {
        ostr << row.toJSON();

    } else {
        response.setStatus(HTTPResponse::HTTPStatus::HTTP_NOT_FOUND);
        ostr << "Item not found";
        return;
    }
}
