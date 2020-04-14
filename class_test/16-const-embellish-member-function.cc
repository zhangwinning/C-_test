#include <iostream>

// const 修饰成员函数
/**
 * 常函数
 *
 * @return
 */

using namespace std;

class Person {
public:

//  在成员函数后面加上 const, 修饰的this 指向，让指针指向的值也不可以修改。
    void showPerson() const {
//        this->m_A = 100;
        this->m_B = 100;
//        this = NULL //
    }

    int m_A;
    mutable int m_B;
};

void test() {
    Person p;
    p.showPerson();
}

void test02() {
    const Person p{}; //
//    p.m_A = 100;
    p.m_B = 100;
    cout << p.m_B << endl;
}

int main() {
    test();
    test02();
}