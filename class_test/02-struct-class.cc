#include <iostream>

using namespace std;

class C1 {
    int m_A;        // class 中的默认权限是私有权限
};

struct C2 {
    int m_A = 10;            // struct中默认权限公共权限
};
int main() {
    C1 c1;
//    c1.m_A = 100;

    C2 c2;
    c2.m_A = 100;
    std::cout << c2.m_A << std::endl;


    return 0;
}