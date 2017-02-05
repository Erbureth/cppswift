#pragma once

#include "token.h"

namespace CppSwift {
namespace Auth {

struct AuthConnInfo {
    Token token;
    std::string url;
};

}
}
