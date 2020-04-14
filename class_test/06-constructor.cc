#include <iostream>

using namespace std;


class Person {
public:
//    构造函数，无返回值，不用写 void
    Person() {
        cout << "构造函数调用" << endl;
    }

//  析构函数没有参数，对象在销毁前，会自动调用析构函数，而且只会调用一次。
    ~Person() {
        cout << "析构函数调用" << endl;
    }

};

void test1() {
    Person p1;//在栈上的数据，
}

int main() {
//    Person p;
    test1();
    system("read -p 'Press Enter to continue...' var");
    return 0;
}
