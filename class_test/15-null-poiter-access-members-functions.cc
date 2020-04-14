#include <iostream>

using namespace std;

// 空指针调用成员函数
class Person {
public:
    void showClassName() {
        cout << "this is showClassName" << endl;
    }

    void showPersonAge() {
        if (this == NULL) {
            return;
        }
        cout << this->m_age << endl;
    }

    int m_age;
};

void test01() {
    Person *p = NULL;
    p->showClassName();
    p->showPersonAge();
}

int main() {
    test01();
}