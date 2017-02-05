#include "../connection.h"
#include "../internal/null_output_iterator.hh"
#include "auth_connection.h"
#include "authenticator.h"
#include "legacy_auth.h"

#include <chrono>
#include <memory>
#include <string>

#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/URI.h>

CppSwift::Auth::AuthConnInfo CppSwift::Auth::LegacyAuth::get_conn_info() {
    Poco::URI uri{url};
    Poco::Net::HTTPClientSession session{
        uri.getHost() + ":" + std::to_string(uri.getPort())
    };
    Poco::Net::HTTPRequest request(
        Poco::Net::HTTPRequest::HTTP_GET,
        uri.getPath() + "auth/v1.0"
    );
    request.add("X-Storage-User", account + ":" + user);
    request.add("X-Storage-Pass", password);

    session.sendRequest(request);

    Poco::Net::HTTPResponse response;
    std::istream &rs = session.receiveResponse(response);
    std::istreambuf_iterator<char> rs_begin{rs}, rs_end;
    std::copy(rs_begin, rs_end, Internal::null_output_iterator());

    AuthConnInfo aci{};
    aci.token.auth_token = response.get("X-Auth-Token");
    aci.token.valid_until = std::chrono::system_clock::now() + std::chrono::seconds(std::stoi(response.get("X-Auth-Token-Expires")));
    aci.url = response.get("X-Storage-Url");

    return aci;
}

std::unique_ptr<CppSwift::Auth::Authenticator> CppSwift::Auth::LegacyAuth::create(
    std::string url,
    std::string account,
    std::string user,
    std::string password
) {
    std::unique_ptr<LegacyAuth> authenticator = std::make_unique<LegacyAuth>();
    authenticator->url = url;
    authenticator->account = account;
    authenticator->user = user;
    authenticator->password = password;
    return std::move(authenticator);
}

