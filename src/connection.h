#pragma once

#include <string>

namespace CppSwift {

struct Connection {
    virtual operator bool() const = 0;
    virtual const std::string & get_url() const = 0;
};

}
