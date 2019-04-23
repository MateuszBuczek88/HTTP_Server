#include "TimeRequestHandlerFactory.h"

HTTPRequestHandler* TimeRequestHandlerFactory::createRequestHandler(const HTTPServerRequest& request)
	{
		if (request.getURI() == "/") 
			return new TimeRequestHandler (_format);
	        else if (request.getURI() == "/hello")
			return new HelloWorldRequestHandler (_format);
		else if (request.getURI() == "/cat")
			return new RandomCatRequestHandler (_format);
		else return 0;
	}
