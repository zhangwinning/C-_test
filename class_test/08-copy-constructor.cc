#include <iostream>

using namespace std;

// copy 调用函数的调用时机
// 1. 使用一个已经创建完毕的对象来初始化一个新对象
// 2. 值传递的方式给函数参数传值
// 3. 值方式返回局部对象

class Person {
public:
    Person() {
        cout << "Person 默认操作函数调用" << endl;
    }

    ~Person() {
        cout << "Person 析构函数调用" << endl;
    }

    int m_Age;

    Person(int age) {
        cout << "Person 有参构造函数调用" << endl;
        m_Age = age;
    }

    Person(const Person &p) {
        cout << "Person copy 函数调用" << endl;
        m_Age = p.m_Age;
    }
};

void test01() {
    Person p1(20);
    Person p2(p1);
    cout << "p2 的年龄是 : " << p2.m_Age << endl;
}

//2. 值传递的方式给函数参数传值，调用 copy 构造函数,相当于 Person p(p1)
void doWork(Person p) {

}

void test02() {
    Person p1;
    doWork(p1);
}

Person dowork2() {
    Person p1;
    return p1;
}

void test03() {
    Person p = dowork2();
}

int main() {

//    test01();
//    test02();
    test03();
}