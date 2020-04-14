#include <iostream>

using namespace std;

class Base {
public:
    int m_A;

    Base() {
        m_A = 100;
    }

    void func() {
        cout << "Base - func 函数调用" << endl;
    }
    void func(int a) {
        cout << "Son - func 函数调用" << endl;
    }
};

class Son : public Base {
public:
    int m_A;

    Son() {
        m_A = 200;
    }

    void func() {
        cout << "Son - func 函数调用" << endl;
    }
};

// 同名属性的处理方式
void test01() {
    Son s;
    cout << s.m_A << endl;
//   如果通过子类对象访问到父类中的同名成员，需要加作用域。
    cout << s.Base::m_A << endl;


}

// 同名函数的处理方式
void test02() {
    Son s;
//
    s.func();   //调用子类的 func，以下加上作用域，就可以调用父类的 func 函数了。
    s.Base::func();

    s.Base::func(100);

}

int main() {
    test01();
    test02();
}

/**
 * 子类可以通过. 方式直接调用其属性，但是调用父属性时，要加作用域。
**/
