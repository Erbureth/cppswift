#include "connection.h"

std::istream& CppSwift::Connection::request(const CppSwift::Net::Method& method, const std::string& endpoint) {
    Net::Response response;
    return request(method, endpoint, response);
}

std::istream & CppSwift::Connection::request(const Net::Method& method, const std::string& endpoint, Net::Response& response) {
    Net::Request request;
    prepare_request(request, method, endpoint);
    send_request(request);

    return receive_response(response);
}


