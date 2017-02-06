#include "auth_connection.h"

CppSwift::Auth::AuthConnection::operator bool() const {
    return static_cast<bool>(token);
}

const std::string & CppSwift::Auth::AuthConnection::get_url() const {
    return url;
}

