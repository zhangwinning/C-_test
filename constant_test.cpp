
/**
 * 常量的定义方式
 * 1. #define 宏常量
 * 2. const 修饰的常量
**/
#include <iostream>
using namespace std;

#define DAY 7

int main() {
    cout << "一周总共多少天" << DAY << "天"<< endl;

//  const 修饰的变量
    const int month=12;
    cout << "一年有" << month << "月份"<< endl;

    int ival = 1024;
    int &refVal = ival;
    cout << &refVal << endl;
    return 0;
}

