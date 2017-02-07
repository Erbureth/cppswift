#pragma once

#include "connection.h"
#include "auth/authenticator.h"

#include <memory>
#include <string>

namespace CppSwift {
class Container;

class Account {
    std::shared_ptr<Connection> connection;
public:
    operator bool();

    std::string get_endpoint() const;

    std::vector<Container> list_containers();

    static Account login(std::unique_ptr<Auth::Authenticator> &&authenticator);
};

}
