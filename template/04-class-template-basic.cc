#include <iostream>

using namespace std;

/**
 * 类模板
 * @return
 */

template<class NameType, class AgeType>
class Person {
public:
    NameType m_Name;
    AgeType m_age;

    Person(NameType name, AgeType age) {
        this->m_Name = name;
        this->m_age = age;
    }

    void show() {
        cout << m_Name << " " << m_age << endl;
    }
};

void test01() {
    Person<string, int> p1("孙悟空", 999);
    p1.show();

}

int main() {
    test01();
}