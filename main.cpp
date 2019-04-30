#include <iostream>
#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Timestamp.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeFormat.h"
#include "Poco/Exception.h"
#include "Poco/ThreadPool.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/Data/MySQL/Connector.h"
#include "Poco/Data/Session.h"
#include "Poco/Data/Statement.h"
#include "TimeRequestHandler.h"
#include "HelloWorldRequestHandler.h"
#include "RandomCatRequestHandler.h"
#include "RequestHandlerFactory.h"
#include "WordRequestHandler.h"

using Poco::Net::ServerSocket;
using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPRequestHandlerFactory;
using Poco::Net::HTTPServer;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Net::HTTPServerParams;
using Poco::Timestamp;
using Poco::DateTimeFormatter;
using Poco::DateTimeFormat;
using Poco::ThreadPool;
using Poco::Util::ServerApplication;
using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::HelpFormatter;


class HTTPTServer: public Poco::Util::ServerApplication {
 public:
    HTTPTServer(): _helpRequested(false) {}
    ~HTTPTServer() {}

 protected:
    void initialize(Application& self) {
        loadConfiguration();
        ServerApplication::initialize(self);
    }

    void uninitialize() {
        ServerApplication::uninitialize();
    }

    void defineOptions(OptionSet& options) {
        ServerApplication::defineOptions(options);
        options.addOption(
            Option("help", "h", "display help information on command line arguments")
                .required(false)
                .repeatable(false));
        options.addOption(
            Option("config", "c", "use config.ini file instead of default params")
                .required(false)
                .repeatable(false)
                .argument("directory", false));
    }

    void handleOption(const std::string& name, const std::string& value) {
        ServerApplication::handleOption(name, value);

        if (name == "help") {
            _helpRequested = true;
        }
        if (name == "config") {
            config_path = value;
        }
    }

    void displayHelp() {
        HelpFormatter helpFormatter(options());
        helpFormatter.setCommand(commandName());
        helpFormatter.setUsage("OPTIONS");
        helpFormatter.setHeader("A web server that serves the current date and time.");
        helpFormatter.format(std::cout);
    }

    int main(const std::vector<std::string>& args) {
        if (_helpRequested) {
            displayHelp();
        } else {
            if (!config_path.empty()) {
                logger().information("Loading configuration file. Path: "+config_path);
                try {
                    loadConfiguration(config_path);
                    logger().information("Config file " + config_path + " successfully loaded");
                    }
                catch (const Poco::InvalidArgumentException & e) {
                    logger().fatal("Failed to load "+config_path);
                }
            }

            unsigned short port = (unsigned short) config().getInt("HTTPServer.port" , 9980);
            std::string format(config().getString("HTTPServer.format", DateTimeFormat::SORTABLE_FORMAT));
            int maxQueued  = config().getInt("HTTPServer.maxQueued", 100);
            int maxThreads = config().getInt("HTTPServer.maxThreads", 16);
            ThreadPool::defaultPool().addCapacity(maxThreads);

            HTTPServerParams* pParams = new HTTPServerParams;
            pParams->setMaxQueued(maxQueued);
            pParams->setMaxThreads(maxThreads);

            ServerSocket svs(port);

            HTTPServer srv(new RequestHandlerFactory(format), svs, pParams);

            srv.start();

            waitForTerminationRequest();

            srv.stop();
        }
        return Application::EXIT_OK;
    }

 private:
    bool _helpRequested;
    std ::string config_path;
};


int main(int argc, char** argv) {
    HTTPTServer app;
    return app.run(argc, argv);
}
