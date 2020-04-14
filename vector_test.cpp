#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

int main() {
//    vector<string> articles = {10, "a"};
//    for(auto i : articles) {
//        std::cout << i << " ";
//    }
//    return 0;
//    vector<int> v2;
//    for(int i = 0; i != 100; i++) {
//        v2.push_back(i);
//    }
//    for(auto i: v2) {
//        std::cout << i << std::endl;
//    }

//    int word;
//    vector<int> text;
//    while (std::cin >> word) {
//        text.push_back(word);
//    }
////    std::cout << text << std::endl;
//
//    for(auto i : text) {
//        std::cout << i << std::endl;
//    }
//    return 0;
    vector<int> v{1,2,3,4,5,6,6,7,8,10};
    for(auto &i: v) {
        i *= i;
    }
    for(auto i : v) {
        std::cout << i << std::endl;
    }

    std::cout << v.size() << std::endl;
    return 0;
}