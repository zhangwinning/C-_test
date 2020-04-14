
// 继承中构造函数和析构的顺序

#include <iostream>

using namespace std;

class Base {
public:
    Base() {
        cout << "Base 的构造函数 " << endl;
    }

    ~Base() {
        cout << "Base 的析构函数" << endl;
    }
};

class Person : public Base {
public:
    Person() {
        cout << "子类的构造函数" << endl;
    }

    ~Person() {
        cout << "子类的析构函数调用" << endl;
    }
};

void test01() {
//  继承中的构造和析构顺序如下:
//  先构造父类，在构造子类，析构的顺序与构造的顺序是相反的。
    Person p;
}

int main() {
    test01();
}