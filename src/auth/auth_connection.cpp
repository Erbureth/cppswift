#include "auth_connection.h"

CppSwift::Auth::AuthConnection::operator bool() {
    return static_cast<bool>(token);
}
