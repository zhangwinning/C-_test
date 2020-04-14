//
// Created by videojj on 2020/4/13.
//

#include "point.h"

/**
 * 如果不加 Point::，这里就默认是全局函数，但是这些函数属于成员函数，所以要加作用域。
 * @param x
 */
void Point::setX(int x) {
    m_X = x;
}

int Point::getX() {
    return m_X;
}

void Point::setY(int y) {
    m_Y = y;
}

int Point::getY() {
    return m_Y;
}
