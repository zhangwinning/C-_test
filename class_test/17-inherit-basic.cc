#include <iostream>

using namespace std;

// 继承实现
class BasePage {
public:
    void header() {
        cout << "公共头部" << endl;
    }

    void footer() {
        cout << "公共底部信息" << endl;
    }

    void left() {
        cout << "公共分类信息列表" << endl;
    }
};

// 语法: class 子类 : 继承方式 父类
class Java : public BasePage {
public:
    void content() {
        cout << "Java 的东西" << endl;
    }
};

void test01() {
    Java java;
    java.content();
    java.left();
    java.footer();
    java.header();
}

int main() {
    test01();
    return 0;
}