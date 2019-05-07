#include "WordsRequestHandler.h"

WordsRequestHandler::WordsRequestHandler() {}

std::string WordsRequestHandler::idsToJSON (const std::vector<int>&ids)
{
    std::stringstream temp;
    temp  << "{ \"ID\" :[ ";
    temp << ids[0];
    for (auto i = ids.begin(); i != ids.end()-1 ;i++) {
        temp << ","<< *(i+1);
    }
    temp  << "]}";
    return temp.str();
}

void WordsRequestHandler::handleRequest(
    HTTPServerRequest& request,
    HTTPServerResponse& response) {

    Application& app = Application::instance();

    app.logger().information(
    "Request from " + request.clientAddress().toString());

    response.setChunkedTransferEncoding(true);
    response.setContentType("application/json");

    Poco::Data::MySQL::Connector::registerConnector();

    std:: string connection_string = "host = localhost;port = 3306;db=words;user=root;password=mynewpassword;compress=true;auto-reconnect=true";

    Session session("MySQL", connection_string);
    Statement select(session);
    std::vector<int>id_list;
    select << "SELECT id  FROM polish_english",
    into(id_list);

    std::ostream& ostr = response.send();
    if (!select.done()) {
        select.execute();
        ostr << idsToJSON(id_list);

    }
}
