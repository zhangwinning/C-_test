#include <iostream>
#include <string>

//using namespace std;
using std::string;

int main() {
    string str("some thing");
    for (auto s: str) {
        std::cout << s << std::endl;
    }

    string s("Hello world !!!!!!!####");
    decltype(s.size()) punct_cnt = 0;
    for (auto c : s) {
        if (ispunct(c)) {
            punct_cnt++;
        }
    }

    std::cout << punct_cnt << std::endl;

    string s1("Hello world !!!");
    for (auto &c: s1) {
        c = toupper(c);
    }
    std::cout << s1 << std::endl;

    string s2("some string");
    if (!s.empty()) {
        s2[0] = toupper(s2[0]);
    }
    std::cout << s2 << std::endl;


    string s3("some string");
    for (decltype(s3.size()) index = 0; index != s3.size() && !isspace(s3[index]); index++) {
        s3[index] = toupper(s3[index]);
    }
    std::cout << s3 << std::endl;
    return 0;
}