#include <iostream>
#include <cpr/cpr.h>

int main() {
    std::cout << "Pick an option: get, post, put, delete, patch or type in 'exit' to exit:" << std::endl;

    while(true) {
        cpr::Response r;
        std::string choice;
        std::cin >> choice;
        if (choice == "exit") break;
        else if (choice == "get") {
            r = cpr::Get(cpr::Url("https://httpbin.org/get"));
            std::cout << "Code: " << r.status_code << std::endl;
            std::cout << "Response: " << r.text << std::endl;
        } else if (choice == "post") {
            std::cout << "Type in form you want to post: (type_name, data)" << std::endl;
            std::string name;
            std::string data;
            std::cin >> name >> data;
            r = cpr::Post(cpr::Url("https://httpbin.org/post"), cpr::Payload({{name, data}}));
            std::cout << "Code: " << r.status_code << std::endl;
            std::cout << "Response: " << r.text << std::endl;
        } else if (choice == "put") {
            std::cout << "Type in form you want to put: (type_name, data)" << std::endl;
            std::string name;
            std::string data;
            std::cin >> name >> data;
            r = cpr::Put(cpr::Url("https://httpbin.org/put"), cpr::Payload({{name, data}}));
            std::cout << "Code: " << r.status_code << std::endl;
            std::cout << "Response: " << r.text << std::endl;
        } else if (choice == "delete") {
            r = cpr::Delete(cpr::Url("https://httpbin.org/delete"));
            std::cout << "Code: " << r.status_code << std::endl;
            std::cout << "Response: " << r.text << std::endl;
        } else if (choice == "patch") {
            std::cout << "Type in form you want to patch: (type_name, data)" << std::endl;
            std::string name;
            std::string data;
            std::cin >> name >> data;
            r = cpr::Patch(cpr::Url("https://httpbin.org/patch"), cpr::Payload({{name, data}}));
            std::cout << "Code: " << r.status_code << std::endl;
            std::cout << "Response: " << r.text << std::endl;
        }
    }

    return 0;
}