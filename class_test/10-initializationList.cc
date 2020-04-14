#include <iostream>

using namespace std;

class Person {

//   传统的初始化操作
public:
    int m_A;
    int m_B;
    int m_C;

    Person(int a, int b, int c) {
        m_A = a;
        m_B = b;
        m_C = c;
    }
};

void test() {
    Person p(10, 20, 30);
    cout << p.m_A << " " << p.m_B << " " << p.m_C << endl;
}

int main() {
    test();
}