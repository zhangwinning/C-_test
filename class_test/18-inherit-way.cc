#include <iostream>

using namespace std;

// 继承中的对象模型
class Base {
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

// 其实在父类中所有的属性都继承下来了。
// 父类中私有成员属性是被编译器隐藏了，因此是访问不到，但是确实是被继承了。
class Son : public Base {
public:
    int m_D;
};

void test01() {
    Son s;
    cout << sizeof(s) << endl;
};

int main() {
    test01();
    return 0;
}