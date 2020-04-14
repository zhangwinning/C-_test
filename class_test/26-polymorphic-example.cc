#include <iostream>

using namespace std;
// 多态案例2， 制作饮品

class AbstractDrinking {
public:
//   煮水
    virtual void Boil() = 0;

//   冲泡
    virtual void Brew() = 0;

//   倒入杯中
    virtual void PourInCup() = 0;

//   加入辅料
    virtual void PutSomething() = 0;

    void makeDrink() {
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
};


//制作 coffer
class Coffee : public AbstractDrinking {
public:
    void Boil() {
        cout << "煮水" << endl;
    }

    void Brew() {
        cout << "冲泡咖啡" << endl;
    }

    void PourInCup() {
        cout << "导入杯中" << endl;
    }

    void PutSomething() {
        cout << "加入糖" << endl;
    }
};


class Tea : public AbstractDrinking {
public:
    void Boil() {
        cout << "煮水" << endl;
    }

    void Brew() {
        cout << "冲泡Tea" << endl;
    }

    void PourInCup() {
        cout << "导入杯中" << endl;
    }

    void PutSomething() {
        cout << "加入T" << endl;
    }
};

// 父类的指针指向子类，实现多态。
void doWork(AbstractDrinking *abs) {    // 相当于 AbstractDrinking *abs = new Coffee
    abs->makeDrink();
    delete abs; // 要把堆区的数据释放掉，防止发生内存泄露。
}


void test01() {
    doWork(new Coffee);
    cout << "======" << endl;
    doWork(new Tea);
}

int main() {
    test01();
}