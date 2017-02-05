#pragma once

#include "authenticator.h"

#include <memory>
#include <string>

namespace CppSwift {
namespace Auth {

    
class LegacyAuth : public virtual Authenticator {
    std::string url;
    std::string account;
    std::string user;
    std::string password;
public:
    virtual AuthConnInfo get_conn_info() override;

    static std::unique_ptr<Authenticator> create(
        std::string url,
        std::string account,
        std::string user,
        std::string password
    );
};

}
}
