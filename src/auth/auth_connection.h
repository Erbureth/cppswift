#pragma once

#include "../connection.h"
#include "authenticator.h"

namespace CppSwift {
namespace Auth {

class AuthConnection : public virtual Connection {
    std::unique_ptr<Authenticator> authenticator;
    Token token;
    std::string scheme;
    std::string host;
    unsigned short port;
    std::string path;

    std::unique_ptr<Net::HTTPSession> session;

    void reauthenticate();
public:
    AuthConnection(std::unique_ptr<Authenticator> &&authenticator);

    virtual operator bool() const override;

    virtual void prepare_request(
        Net::Request &request,
        const Net::Method &method,
        const std::string &endpoint
    ) override;
    virtual std::ostream & send_request(Net::Request &request) override;
    virtual std::istream & receive_response(Net::Response &response) override;
};

}
}
