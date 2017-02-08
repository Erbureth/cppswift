#include "object.h"

CppSwift::Object::operator bool() {
    return !container_endpoint.empty()
        && static_cast<bool>(connection)
        && static_cast<bool>(*connection);
}

std::string CppSwift::Object::get_endpoint() const {
    return container_endpoint + path;
}


