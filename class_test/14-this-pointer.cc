
//this 指针指向被调用的成员函数所属的对象， 解决名称冲突
//

#include <iostream>

using namespace std;

class Person {
public:
    Person(int age) {
//      this 指针指向被调用的成员函数所有的对象
        this->age = age;
    }

    Person(const Person &p) {
        cout << "copy constructor invoker" << endl;
    }

//  返回值是值的方式: 这里是创建了一个新对象(是通过调用 copy 构造函数创建的)，而如果是通过引用的方式返回，就不会创建一个新对象。
//  就会一直返回 p。
    Person &PersonAddAge(Person &p) {
        this->age += p.age;
//      this 是指向 p2 的指针，而 *this 指向的是 p2 这个对象本体。
        return *this;
    }

    int age;
};

void test01() {
    Person p(10);
    cout << p.age << endl;
}

void test02() {
    Person p1(10);
    Person p2(20);
//   链式编程思想
    p1.PersonAddAge(p2).PersonAddAge(p2);
    cout << p1.age << endl;
}

int main() {
    test02();
//    test01();
}