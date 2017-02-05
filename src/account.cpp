#include "account.h"

bool CppSwift::Account::is_valid() {
    return !auth_token.empty();
}


CppSwift::Account CppSwift::Account::login() {
    Account account;
    account.auth_token = "xxx";
    return account;
}

