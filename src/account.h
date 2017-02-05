#pragma once

#include <string>

namespace CppSwift {

class Account {
    std::string auth_token;
public:
    bool is_valid();

    static Account login();
};

}
