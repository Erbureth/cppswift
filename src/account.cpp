#include "account.h"
#include "auth/auth_connection.h"
#include "container.h"

CppSwift::Account::operator bool() {
    return static_cast<bool>(connection) && static_cast<bool>(*connection);
}

std::string CppSwift::Account::get_endpoint() const {
    return "/";
}


std::vector<CppSwift::Container> CppSwift::Account::list_containers() {
    std::vector<Container> containers;
    //TODO: Use JSON format the next time
    std::istream & data = connection->request(Net::Request::HTTP_GET, get_endpoint());
    std::string container_name;
    while (data >> container_name) {
        containers.push_back(Container(container_name));
        containers.back().set_connection(connection);
        containers.back().bind_account(*this);
    }

    return containers;
}


CppSwift::Account CppSwift::Account::login(std::unique_ptr<CppSwift::Auth::Authenticator> &&authenticator) {
    Account account;
    account.connection = std::make_shared<Auth::AuthConnection>(std::move(authenticator));
    return account;
}

