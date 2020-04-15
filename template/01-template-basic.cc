/**
 * 本阶段主要针对 c++ 泛型编程和 STL 技术做详细讲解，探讨 C++ 更深层的应用
 * 模板: 模板就是建立通用的磨具，大大提高复用性。
 * c++ 中另一种编程思想是 泛型编程，主要利用技术是模板
 * c++ 提供两种模板机制: 函数模板和类模板。
 *
 * 函数模板的作用
 * 建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个虚拟的类型来代表。
**/

#include <iostream>

using namespace std;

//比如实现个交换整形的函数
void swapInt(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapDouble(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

void test01() {
    int a = 10;
    int b = 20;
    swapInt(a, b);
    cout << a << " " << b << endl;

    double c = 1.1;
    double d = 1.2;
    swapDouble(c, d);
    cout << c << " " << d << endl;

}

// 函数模板
// 声明一个模板，告诉编译器后面代码中紧跟着的 T 不可报错，T 是一个通用的数据类型
template<typename T>
void mySwap(T &a, T &b) {
    cout << "Size of value is : " << sizeof(T) << endl;
    T temp = a;
    a = b;
    b = temp;
}

void test02() {
    int a = 10, b = 20;
//  利用函数模板交换
//  两种方式使用函数模板1. 自动类型推导
    mySwap(a, b);
    cout << a << " " << b << endl;

//  显式指定类型
    double c = 1.1, d = 1.2;
    mySwap<double>(c, d);
    cout << c << " " << d << endl;
}

int main() {
//    test01();
    test02();
    return 0;
}