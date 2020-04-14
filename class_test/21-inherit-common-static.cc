#include <iostream>

using namespace std;
// 继承中

class Base {
public:
    static int m_A;

    static void func() {
        cout << "Base - static void func()" << endl;
    }
};

int  Base::m_A = 100;

class Son : public Base {
public:
    static int m_A;

    static void func() {
        cout << "Son - static void func()" << endl;
    }
};

// 作用域
int Son::m_A = 200;

void test01() {
//  通过对象的方式访问
    Son s;
    cout << "Son 下 m_A = " << s.m_A << endl;
    cout << "Base 下 m_A = " << s.Base::m_A << endl;

    cout << "通过类名的方式" << endl;
//  通过类名的方式访问
    cout << "Son 下 m_A = " << Son::m_A << endl;
//  第一个双冒号表示通过类名的方式进行访问，第二个 :: 表示访问父类作用域。
    cout << "Base 下的 m_A =" << Son::Base::m_A << endl;
}


void test02() {
    Son s;
    s.func();
//  :: 表示是 Base 作用域下的 func.
    s.Base::func();

    cout << "use class invoke static func" << endl;
    Son::func();
    Son::Base::func();
}

int main() {
//    test01();
    test02();
}