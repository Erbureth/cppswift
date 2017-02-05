#include "account.h"

CppSwift::Account::operator bool() {
    return static_cast<bool>(connection) && static_cast<bool>(*connection);
}


CppSwift::Account CppSwift::Account::login() {
    Account account;
    return account;
}

