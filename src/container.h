#pragma once

#include <memory>
#include "connection.h"

namespace CppSwift {

class Account;

class Container {
    std::string account_endpoint;
    std::shared_ptr<Connection> connection;

    std::string name;
public:
    Container(const std::string &name) : name(name) {}
    operator bool();

    std::string get_endpoint() const;
    void set_connection(std::shared_ptr<Connection> &connection);
    void bind_account(const Account &account);
};

}

