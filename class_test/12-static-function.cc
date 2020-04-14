#include <iostream>

using namespace std;

/**
 * 静态成员函数。
 * 所有的对象共享同一个函数
 * 静态成员函数只能访问静态成员变量
 * @return
 */
class Person {
public:
    static void func() {
        m_Age = 100;    // 静态成员函数可以访问静态成员变量的。
        cout << "static void invoker " << m_Age << endl;
    }

    static int m_Age;
};

int Person::m_Age = 10; // 静态成员变量必须要在类外初始化。

// 静态成员函数也是会有访问权限的。
void test01() {
//  1.通过对象来调用
    Person p;
    p.func();

//  2.通过类名调用，Person作用域下的func
    Person::func();
}

int main() {
    test01();
}