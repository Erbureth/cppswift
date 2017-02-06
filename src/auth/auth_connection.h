#pragma once

#include "../connection.h"
#include "authenticator.h"

namespace CppSwift {
namespace Auth {

class AuthConnection : public virtual Connection {
    std::unique_ptr<Authenticator> authenticator;
    Token token;
    std::string url;
public:
    AuthConnection(std::unique_ptr<Authenticator> &&authenticator)
     : authenticator(std::move(authenticator)) {
         AuthConnInfo aci = this->authenticator->get_conn_info();
         token = aci.token;
         url = aci.url;
    }

    virtual operator bool() const override;
    virtual const std::string & get_url() const override;
};

}
}
