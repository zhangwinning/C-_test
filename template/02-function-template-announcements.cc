/**
 * 函数模板注意事项
 * 1. 自动类型推导，必须推导出一致的数据类型 T, 才可以使用
 * 2. 模板必须要确定T的数据类型，才可以使用。
**/

#include <iostream>

using namespace std;

template<class T>
void mySwap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

void test01() {
    double a = 1.1, b = 1.2;
    char f = 'c';
//    mySwap(a, f);   // 错误！ 推导不出一致的数据类型 T
    cout << a << " " << b << endl;

//  显式类型指定
    int c = 10, d = 20;
    mySwap<int>(c, d);
    cout << c << "  " << d << endl;
}

// 2.模板必须要确定出 T的数据类型，才可以使用
template<class T>
void func() {
    cout << "func invoke" << endl;
}

void test02() {
//    func()  这种方式是错误的，即使函数代码里面没用函数模板(只是定义时用到)，调用时也要指定函数模板。
    func<int>();
}

int main() {
    test01();
}