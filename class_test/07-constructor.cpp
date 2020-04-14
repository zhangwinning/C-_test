#include <iostream>

using namespace std;

class Person {
public:
    Person() {
        cout << "Person 构造函数调用" << endl;
    }

    Person(int a) {
        age = a;
        cout << "Person 的有参构造函数调动" << endl;
    }

//   拷贝构造函数调用
    Person(const  Person &p) {
        cout << "Person copy 调用函数" << endl;
        age = p.age;
    }

    ~Person() {
        cout << "Person 析构函数调用" << endl;
    }

    int age;
};

void test1() {
//    Person p1;   // 默认构造函数调用
//    Person p2(10);  // 有参构造函数调用
//    Person p3(p2);

//    cout << "p2 的年龄是" << p2.age << endl;
//    cout << "p3 的年龄是" << p3.age << endl;
//    Person p1();

//    Person p1;
//    Person p2 = Person(10);
//    Person p3 = Person(p2);


    Person p4 = 10;

    Person p5 = p4;



//
}

int main() {
//    Person p;
    test1();
}