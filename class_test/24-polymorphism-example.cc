#include <iostream>

using namespace std;

// 分别使用普通的写法和多态技术实现计算器

class Calculator {
public:
    int m_Num1;
    int m_Num2;

    int getResult(string oper) {
        if (oper == "+") {
            return m_Num1 + m_Num2;
        } else if (oper == "-") {
            return m_Num1 - m_Num2;
        }

//      如果想要扩展新的功能，需要修改源码，在真实的开发中，提倡开闭原则。
//      开闭原则: 对扩展进行开发，对修改进行关闭。

        return 0;
    };
};

void test01() {
//
    Calculator c;
    c.m_Num1 = 10, c.m_Num2 = 20;
    cout << c.getResult("+") << endl;
    cout << c.getResult("-") << endl;
    cout << c.getResult("") << endl;
};


//========================================利用多态实现计算器========================================================
// 实现计算器的抽象类
class AbstractCalculator {
public:
    int m_Num1;
    int m_Num2;

//   关键点，要实现虚函数，父类中要定义虚函数，子类中去重写这个函数。
    virtual int getResult() {
        return 0;
    }
};


// 加法计算器类
class AddCalculator : public AbstractCalculator {
public:
    int getResult() {
        return m_Num1 + m_Num2;
    }
};

// 减法计算类
class SubCalculator : public AbstractCalculator {
public:
    int getResult() {
        return m_Num1 - m_Num2;
    }
};


void test02() {
//      多态使用条件
//      父类指针或者引用指向子类对象, new 是会申请堆中数据的。并且要 new 申请，手动释放。
    AbstractCalculator *abc = new AddCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 20;
    cout << "+" << abc->getResult() << endl;

    delete abc;

    abc = new SubCalculator();
    abc->m_Num1 = 200;
    abc->m_Num2 = 300;

    cout << abc->m_Num1 << " " << abc->m_Num2 << endl;
    cout << "-" << abc->getResult() << endl;

    delete abc;

}

int main() {
//    test01();
    test02();
}