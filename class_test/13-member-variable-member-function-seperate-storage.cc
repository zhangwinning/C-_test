#include <iostream>

using namespace std;

class Person {
    int m_A;
//  静态成员变量不属于类对象
    static int m_B; //静态成员变量的特点是: 类内声明，类外定义

//  非静态成员函数是独一无二的一份，也不属于类对象
    void func() {

    }
//  静态成员函数是独一无二的一份，也不属于类对象
    static void func1() {

    }
};

int Person::m_B = 0;

void test01() {
    Person p;
//  查看一个对象占据多少内存空间==> 1 个字节
//  c++ 编译器会给每个空对象也分配一个字节空间，是为了区分空对象占据内存的位置。
//  每个空对象应该有一个独一无二的区分度
    cout << "size of p: " << sizeof(p) << endl;
}

void test02() {
    Person p;
    cout << "size of p: " << sizeof(p) << endl;
}

int main() {
    test02();
}