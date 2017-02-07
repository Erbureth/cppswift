#include "account.h"
#include "container.h"

CppSwift::Container::operator bool() {
    return !account_endpoint.empty()
        && static_cast<bool>(connection)
        && static_cast<bool>(*connection);
}

std::string CppSwift::Container::get_endpoint() const {
    return account_endpoint + name + "/";
}


void CppSwift::Container::set_connection(std::shared_ptr<Connection>& connection) {
    this->connection = connection;
}


void CppSwift::Container::bind_account(const CppSwift::Account& account) {
    this->account_endpoint = account.get_endpoint();
}

