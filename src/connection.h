#pragma once

#include <string>
#include "net/net.h"

namespace CppSwift {

struct Connection {
    virtual operator bool() const = 0;
    virtual void prepare_request(
        Net::Request &request,
        const Net::Method &method,
        const std::string &endpoint
    ) = 0;
    virtual std::ostream & send_request(Net::Request &request) = 0;
    virtual std::istream & receive_response(Net::Response &response) = 0;

    virtual std::istream & request(
        const Net::Method &method, 
        const std::string &endpoint
    );

    virtual std::istream &request(
        const Net::Method &method, 
        const std::string &endpoint,
        Net::Response &response
    );
};

}
