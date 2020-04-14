
/**
 * 多态是 C++ 面向对象的三大特性之一
 * 多态分为两种:
 * 1. 静态多态, 函数重载和运算符重载属于静态多态，复用函数名
 * 2. 动态多态, 派生类和虚函数实现运行时多态。
 *
 * 静态多态和动态多态区别:
 * - 静态多态和函数地址早绑定 - 编译阶段确定函数地址
 * - 动态多态的函数地址晚绑定 - 运行时确定函数地址
 *
 */
#include <iostream>

using namespace std;


class Animal {
public:
    virtual void speak() {
        cout << "动物在说话" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() {
        cout << "小猫在说话" << endl;
    }
};


class Dog : public Animal {
public:
    void speak() {
        cout << "小狗在说话" << endl;
    }
};

// 地址早绑定，在编译阶段确定函数地址
// 如果想执行猫在说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定.
// 通过在父类中定义函数为 virtual


/**
 * 动态多态满足条件
 * 1. 有继承关系
 * 2. 子类要重写父类中的虚函数
 *
 * 动态多态的使用
 * 父类的引用或者指针指向子类对象
 */
void doSpeak(Animal &animal) {
    animal.speak();
}

void test01() {
    Cat cat;
    doSpeak(cat);

    Dog dog;
    doSpeak(dog);
}

int main() {
    test01();
}