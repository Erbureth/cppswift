#pragma once

#include <string>
#include <chrono>

namespace CppSwift {
namespace Auth {

struct Token {
    std::string auth_token;
    std::chrono::time_point<std::chrono::system_clock> valid_until;

    operator bool() {
        return !auth_token.empty() && valid_until > std::chrono::system_clock::now();
    }
};
}
}
