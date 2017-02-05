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
    virtual operator bool() override;
};

}
}
