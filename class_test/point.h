//
// Created by videojj on 2020/4/13.
//
//#pragma once    // 防止头文件重复包含
//#pragma once
//
#ifndef C__TEST_POINT_H
#define C__TEST_POINT_H
#include <iostream>

using namespace std;
class Point {
private:
    int m_X;
    int m_Y;
public:
    void setX(int x);

    int getX();

    void setY(int y);
    int getY();
};


#endif //C__TEST_POINT_H
