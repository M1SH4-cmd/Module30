#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cpr/cpr.h>

int main() {
    std::map<std::string, std::string> arguments;
    std::string key, value;

    while (true) {
        std::cout << "Enter args name (or 'post'/'get' to send request): ";
        std::getline(std::cin, key);

        if (key == "post" || key == "get") {
            break;
        }

        std::cout << "Enter args value: ";
        std::getline(std::cin, value);

        if (!key.empty() && !value.empty()) {
            arguments.insert(std::make_pair(key, value));
        } else {
            std::cout << "Key and value cannot be empty." << std::endl;
        }
    }

    if (key == "post") {
        std::vector<cpr::Pair> payload;
        for (std::map<std::string, std::string>::iterator it = arguments.begin(); it != arguments.end(); ++it) {
            payload.emplace_back(it->first, it->second);
        }

        cpr::Response response = cpr::Post(cpr::Url{"https://httpbin.org/post"},
                                           cpr::Payload{payload.begin(), payload.end()});

        std::cout << "Servers respond (POST): " << response.text << std::endl;
    } else if (key == "get") {
        std::string url = "https://httpbin.org/get?";
        for (std::map<std::string, std::string>::iterator it = arguments.begin(); it != arguments.end(); ++it) {
            url += it->first + "=" + it->second + "&";
        }
        if (!arguments.empty()) {
            url.pop_back();
        }

        cpr::Response response = cpr::Get(cpr::Url{url});

        std::cout << "Servers respond (GET): " << response.text << std::endl;
    } else {
        std::cout << "Incorrect request method." << std::endl;
    }

    return 0;
}