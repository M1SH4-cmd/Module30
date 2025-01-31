#include <iostream>
#include <cpr/cpr.h>

int main() {
//    cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/headers"),
//                               cpr::Header({{"user-agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/130.0.0.0 Safari/537.36 OPR/115.0.0.0"},
//                                                            {"Accept", "text/html"}}));

    std::string name, city;
    std::cin >> name>> city;

    cpr::Response r2 = cpr::Post(cpr::Url("http://httpbin.org/post"),
                                 cpr::Payload({{"name", name.c_str()},
                                                                {"city", city.c_str()}}));

    std::cout << "Response status: " << r2.status_code << std::endl;
    std::cout << "Response body: " << r2.text << std::endl;
    return 0;
}
