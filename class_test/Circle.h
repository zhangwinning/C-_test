//
// Created by videojj on 2020/4/13.
//

#pragma once    // 防止头文件重复包含


#include <iostream>
using namespace std;

#include "point.h"

class Circle {
public:
    void setR(int r);

    int getR();

    void setCenter(Point center);

    Point getCenter();

    void isInCircle(Point &p);

private:
    int m_R;    // 半径
//  在类中可以让另一个类作为本类中的成员存在。
    Point m_Center;     // 圆心
};


