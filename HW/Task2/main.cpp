#include <iostream>
#include <string>
#include <cpr/cpr.h>

int main() {
    cpr::Response response = cpr::Get(cpr::Url{"https://httpbin.org/html"},
                                      cpr::Header{{"accept", "text/html"}});

    if (response.status_code == 200) {
        std::string body = response.text;
        std::string::size_type start = body.find("<h1>");
        std::string::size_type end = body.find("</h1>");

        if (start != -1 && end != -1) {
            if (start < end) {
                start += 4;
                std::string title = body.substr(start, end - start);
                std::cout << "Header of article:\n" << title << std::endl;
            } else {
                std::cout << "Tag <h1> is found after </h1>, which is impossible." << std::endl;
            }
        } else {
            std::cout << "Tags <h1> or </h1> not found." << std::endl;
        }
    } else {
        std::cout << "Error occured: " << response.status_code << std::endl;
    }

    return 0;
}