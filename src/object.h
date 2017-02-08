#pragma once

#include <memory>
#include "connection.h"

namespace CppSwift {

class Container;

class Object {
    std::string container_endpoint;
    std::shared_ptr<Connection> connection;

    std::string path;
public:
    Object(const std::string &path) : path(path) {}
    operator bool();

    std::string get_endpoint() const;
    void set_connection(std::shared_ptr<Connection> &connection);
    void bind_container(const Container &container);
};

}
