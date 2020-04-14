#include <iostream>

using namespace std;

class Cube {
public:
//   设置长
    void setL(int l) {
        m_L = l;
    }

    int getL() {
        return m_L;
    }

    //   设置W
    void setW(int w) {
        m_W = w;
    }

    int getW() {
        return m_W;
    }

    //   设置H
    void setH(int h) {
        m_H = h;
    }

    int getH() {
        return m_H;
    }

    int calculates() {
        return 2 * m_L * m_W + 2 * m_L * m_H + 2 * m_W * m_H;
    }

    int calculateV() {
        return m_L * m_W * m_H;
    }


    bool isSmaeByClass(Cube &c) {
        if (m_H == c.getH()) {
            return true;
        }
        return  false;
    }

private:
    int m_L;
    int m_W;
    int m_H;
};

bool isSame(Cube &c1, Cube &c2) {
    if (c1.getH() == c2.getH()) {
        return true;
    }
    return false;
}

int main() {
    Cube c;
    c.setL(1);
    c.setW(1);
    c.setH(1);

    cout << c.getH() << endl;
    cout << c.calculates() << endl;
    cout << c.calculateV() << endl;


    Cube c2;
    c2.setH(1);
    cout << isSame(c, c2) << endl;

    bool value = c.isSmaeByClass(c2);
    cout << value << endl;
}