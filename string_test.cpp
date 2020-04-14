#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main() {
//    string s1 = "hello";
//    cout << s1 << endl;
//
//    string s4(10, 'c');
//    cout << s4 << endl;


    string s1 = "hello";
    string s2(s1);  // 相当于  string s2 = s1
    cout << s1 << s2 << endl;

    string s3("Value"); // 直接初始化(使用等号)和copy初始化(不使用等号)
    string s4(10, 'c');
    cout << s3 << "\n" << s4 << endl;


    string s;
    cin >> s;
    cout << s << endl;

    string s10, s11;
    cin >> s10 >> s11;
    cout << s10 << "\t" << s11 << endl;
    return 0;
}