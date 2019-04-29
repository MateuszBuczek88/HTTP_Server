#include "MySQLRequestHandler.h"
using namespace std;

struct Words {
    int id;
    std::string polish;
    std::string english;
};

int count_id = 0;

MySQLRequestHandler::MySQLRequestHandler() {}
MySQLRequestHandler::MySQLRequestHandler(std::vector<std::string> _uri_seg):uri_seg(_uri_seg) {}

void MySQLRequestHandler::handleRequest(
    HTTPServerRequest& request,
    HTTPServerResponse& response) {

    Application& app = Application::instance();

    app.logger().information(
    "Request from " + request.clientAddress().toString());

    response.setChunkedTransferEncoding(true);
    response.setContentType("text/html");
    Words row;
    Poco::Data::MySQL::Connector::registerConnector();

    std:: string connection_string = "host=localhost;port=3306;db=words;user=root;password=mynewpassword;compress=true;auto-reconnect=true";

    Session session("MySQL", connection_string);
    Statement select(session);

    select << "SELECT id, polish, english FROM polish_english WHERE id="+uri_seg[1],
    into(row.id),
    into(row.polish),
    into(row.english),
    range(0 , 1);

    Statement select_c(session);
    select_c << "SELECT count(id)  FROM polish_english",
    into(count_id),
    range(0 , 1);
    select_c.execute();


    std::ostream& ostr = response.send();

    if (count_id < (std::stoi(uri_seg[1]))) {
        ostr << "<html><head><title>HTTPTimeServer powered by POCO C++ Libraries</title>";
        ostr << "<meta http-equiv=\"refresh\" content=\"100\"></head>";
        ostr << "<body><p style=\"text-align: center; font-size: 48px;\">";
        ostr << "Wrong index number,choose index between: 1- " <<count_id;
        ostr << "</p></body></html>";
    } else {
        while (!select.done()) {
            select.execute();

            ostr << "<html><head><title>HTTPTimeServer powered by POCO C++ Libraries</title>";
            ostr << "<meta http-equiv=\"refresh\" content=\"100\"></head>";
            ostr << "<body><p style=\"text-align: center; font-size: 48px;\">";
            ostr << row.id << " " <<row.polish << " " <<row.english;
            ostr << "</p></body></html>";
        }
    }
}
