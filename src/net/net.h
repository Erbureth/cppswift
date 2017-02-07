#pragma once

#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>

namespace CppSwift {
namespace Net {
    using HTTPSession = Poco::Net::HTTPClientSession;
    using Request = Poco::Net::HTTPRequest;
    using Response = Poco::Net::HTTPResponse;
    using Method = decltype(Poco::Net::HTTPRequest::HTTP_GET);
}
}
