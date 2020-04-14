#include <iostream>
//
using namespace std;

#include "Circle.h"
#include "point.h"

int main() {
    Circle c1;
    Point p1;
    c1.setR(10);

    p1.setX(0);
    p1.setY(0);
    c1.setCenter(p1);


    Point p2;       // 点
    p2.setX(0);
    p2.setY(11);
//    isInCircle(c1, p2);

    c1.isInCircle(p2);
    return 0;
}