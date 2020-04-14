#include <iostream>

using namespace std;

const double PI = 3.14;

class Circle {
//   圆的属性和圆的方式
public:
    int m_r;

    double calculateZC() {
        return 2 * PI * m_r;
    }
};

int main() {
//  通过一个类来实例化一个对象
    Circle c1;
    c1.m_r = 10;
    std::cout << c1.calculateZC() << std::endl;
}