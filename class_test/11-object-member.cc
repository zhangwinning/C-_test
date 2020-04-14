#include <iostream>

using namespace std;

// 当其他类的对象作为本类成员时，构造时候先构造类对象，再构造自身。
class Phone {
public:
    string m_PName;

    Phone(string name) {
        cout << "phone1" << endl;
        m_PName = name;
    }
};

class Person {
public:
    string m_Name;
    Phone m_Phone;

//    Phone m_phone = pName // 隐式转换法
    Person(string name, string phone) : m_Name(name), m_Phone(phone) {
//        m_Name = name;
//        m_Phone = phone;
        cout << "Person " << endl;
    }
};

void test01() {
    Person p("张三", "max");
    cout << p.m_Name << p.m_Phone.m_PName << endl;
};

int main() {
    test01();
}