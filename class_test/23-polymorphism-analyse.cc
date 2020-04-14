
/**
 * Animal 内部结构 vfptr(虚函数(表)指针) v - virtual| f - function | ptr - pointer |
 *
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

void doSpeak(Animal &animal) {
    animal.speak();
}

void test02() {
    cout << "Size of Animal = " << sizeof(Animal) << endl;
}

int main() {
    test02();
}