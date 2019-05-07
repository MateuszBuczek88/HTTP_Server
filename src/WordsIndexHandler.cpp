#include "WordsIndexHandler.h"

WordsIndexHandler::WordsIndexHandler() {}

void WordsIndexHandler::handleRequest(
    HTTPServerRequest& request,
    HTTPServerResponse& response) {

    Application& app = Application::instance();

    app.logger().information(
    "Request from " + request.clientAddress().toString());

    response.setChunkedTransferEncoding(true);
    response.setContentType("text/html");

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
        ostr  << "{ \"ID\" :[ ";
        ostr << id_list[0];
        for (auto i = id_list.begin(); i != id_list.end()-1 ;i++) {
            ostr << ","<< *(i+1);
        }
        ostr  << "]}";
    }
}
