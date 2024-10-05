#include <boost/asio.hpp>

#include <exception>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

namespace net = boost::asio;
using tcp = net::ip::tcp;

std::vector<std::string> GetIpAddress(std::string_view hostname) {
    std::vector<std::string> ips;

    try {
        net::io_context io;
        tcp::resolver resolver(io);
        tcp::resolver::results_type endpoints = resolver.resolve(tcp::v4(), hostname.data(), "");

        for (auto endpoint = endpoints.begin(); endpoint != endpoints.end(); ++endpoint) {
            ips.push_back(((tcp::endpoint)*endpoint).address().to_string());
        }
    }
    catch (const std::exception& e) {
        std::cerr << "exception: " << e.what() << std::endl;
    }

    return ips;
}

int main() {
    std::string hostname;

    std::cout << "Hostname:\n";
    std::getline(std::cin, hostname);

    auto ips = GetIpAddress(hostname);

    for (const auto& ip : ips) {
        std::cout << ip << std::endl;
    }
}
