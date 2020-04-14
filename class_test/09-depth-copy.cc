#include <iostream>

using namespace std;

class Person {
public:
    Person() {
        cout << "Person 的无参构造函数调用" << endl;
    }

    Person(int age, int height) {
        m_Age = age;
        m_Height = new int(height);
        cout << "Person 的有参构造函数调用" << endl;
    }

//  重写 copy 构造函数
    Person(const Person &p) {
        m_Age = p.m_Age;
//        m_Height = p.m_Height;
        m_Height = new int(*p.m_Height);   // 应用深copy
    }
//  浅 copy 带来的问题是堆区的内存重复释放。
    ~Person() {
        if (m_Height != NULL) {
            delete m_Height;    // 把堆中地址清空
            m_Height = NULL;    // 避免出现野指针
        }
        cout << "Person 的析构函数调用" << endl;
    }

    int m_Age;
    int *m_Height;  // 表示从堆中分配一块内存
};

void test01() {
    Person p1(19, 180);
    cout << p1.m_Age <<p1.m_Height << " "<< *p1.m_Height<< endl;

    Person p2(p1);
    cout << p2.m_Age << p2.m_Height << " "<< *p2.m_Height<<endl;
}

int main() {
    test01();
    return 0;
}