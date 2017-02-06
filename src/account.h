#pragma once

#include "connection.h"
#include "auth/authenticator.h"

#include <memory>
#include <string>

namespace CppSwift {

class Account {
    std::shared_ptr<Connection> connection;
public:
    operator bool();

    static Account login(std::unique_ptr<Auth::Authenticator> &&authenticator);
};

}
