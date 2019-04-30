#include "WordsIndexHandler.h"

int index_count;

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

    std:: string connection_string = "host=localhost;port=3306;db=words;user=root;password=mynewpassword;compress=true;auto-reconnect=true";

    Session session("MySQL", connection_string);
    Statement select(session);
    std::vector<int>id_list;
    select << "SELECT id  FROM polish_english",
    into(id_list);

    std::ostream& ostr = response.send();
    if (!select.done()) {
        select.execute();
        ostr << "<html><head><title>HTTPServer powered by POCO C++ Libraries</title>";
        ostr << "<meta http-equiv=\"refresh\" content=\"100\"></head>";
        ostr << "<body><p style=\"text-align: center; font-size: 48px;\">";
        ostr << "ID's list: ";
        for (auto a : id_list) {
            ostr  << a << ", ";
        }
        ostr << "</p></body></html>";
    }
}
