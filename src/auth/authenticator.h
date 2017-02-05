#pragma once

#include <memory>

#include "../connection.h"
#include "auth_conn_info.h"

namespace CppSwift {
namespace Auth {

struct Authenticator {
    virtual AuthConnInfo get_conn_info() = 0;
};

}
}
