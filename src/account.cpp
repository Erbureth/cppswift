#include "account.h"
#include "auth/auth_connection.h"

CppSwift::Account::operator bool() {
    return static_cast<bool>(connection) && static_cast<bool>(*connection);
}


CppSwift::Account CppSwift::Account::login(std::unique_ptr<CppSwift::Auth::Authenticator> &&authenticator) {
    Account account;
    account.connection = std::make_shared<Auth::AuthConnection>(std::move(authenticator));
    return account;
}

