//
// Created by videojj on 2020/4/13.
//

#include "Circle.h"

void Circle::setR(int r) {
    m_R = r;
}

int Circle::getR() {
    return m_R;
}

void Circle::setCenter(Point center) {
    m_Center = center;
}

Point Circle::getCenter() {
    return m_Center;
}

void Circle::isInCircle(Point &p) {
    int distance = (m_Center.getX() - p.getX()) * (m_Center.getX() - p.getX()) +
                   (m_Center.getY() - p.getY()) * (m_Center.getY() - p.getY());
    int rDistance = m_R * m_R;
    if (distance == rDistance) {
        cout << "点在圆上" << endl;
    } else if (distance < rDistance) {
        cout << "点在园内" << endl;
    } else {
        cout << "点在院外" << endl;
    }
}

