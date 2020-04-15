#include <iostream>

using namespace std;

// 类模板和函数模板的区别
template<class NameType, class AgeType = int>
class Person {
public:
    Person(NameType name, AgeType age) {
        this->name = name;
        this->age = age;
    }

    void show() {
        cout << name << " " << age << endl;
    }

private:
    NameType name;
    AgeType age;
};

//类模板没有自动类型推导使用方式 只能用显示指定类型
void test01() {
    Person<string, int> p1("张飒", 123);
    p1.show();
}

void test02() {
    Person<string> p2("猪八戒", 20);
    p2.show();

}

int main() {
    test01();
    test02();
}