/**
 * 纯虚函数与抽象类
 *
**/
#include <iostream>

using namespace std;

//类中只要有一个纯虚函数，这个类称为抽象类。
// 抽象类的特点
// 1. 无法实例化对象 2.抽象类的子类必须重写父类中的纯虚函数，否则也属于抽象类。

class Base {
public:
    virtual void func() = 0;    // 这是一个纯虚函数
};

class Son : public Base {
public:
    void func() {
        cout << "Son invoke" << endl;
    }
};

void test01() {
    Son s;
    s.func();

//  通过多态的方式调用，父类中指针或者引用指向子类对象。
    Base *base = new Son();
    base->func();
}

int main() {
    test01();
}