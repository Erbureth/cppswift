#include "auth_connection.h"

#include <Poco/URI.h>

CppSwift::Auth::AuthConnection::AuthConnection(std::unique_ptr<Authenticator> && authenticator)
    : authenticator(std::move(authenticator))
{
    reauthenticate();
}

void CppSwift::Auth::AuthConnection::reauthenticate() {
    AuthConnInfo aci = authenticator->get_conn_info();
    token = aci.token;

    Poco::URI uri{aci.url};
    scheme = uri.getScheme();
    host = uri.getHost();
    port = uri.getPort();
    path = uri.getPath();

    session = std::make_unique<Net::HTTPSession>(host, port);
}


CppSwift::Auth::AuthConnection::operator bool() const {
    return static_cast<bool>(token);
}

void CppSwift::Auth::AuthConnection::prepare_request(Net::Request& request, const Net::Method& method, const std::string& endpoint) {
    if (!token) {
        reauthenticate();
    }

    request.setMethod(method);
    request.setURI(path + endpoint);
    request.add("X-Auth-Token", token.auth_token);
}

std::ostream & CppSwift::Auth::AuthConnection::send_request(Net::Request& request) {
    return session->sendRequest(request);
}

std::istream & CppSwift::Auth::AuthConnection::receive_response(Net::Response& response) {
    return session->receiveResponse(response);
}

