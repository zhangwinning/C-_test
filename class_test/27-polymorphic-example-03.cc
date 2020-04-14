#include <iostream>

using namespace std;

// 抽象不同零件类
// 抽象CPU类
class CPU {
public:
    virtual void calculate() = 0;
};

// 抽象显卡类
class VideoCard {
public:
    virtual void display() = 0;
};

// 内存条
class Memory {
public:
//    抽象的存储函数
    virtual void storage() = 0;
};


class Computer {
public:
    Computer(CPU *cpu, VideoCard *vc, Memory *mem) {
        m_Cpu = cpu;
        m_Vc = vc;
        m_Mem = mem;
    }

    ~Computer() {
        if (m_Cpu != NULL) {
            delete m_Cpu;   // 释放堆中内存
            m_Cpu = NULL;   // 把这个指向堆中的指针指向 NULL
        }

        if (m_Mem != NULL) {
            delete m_Mem;
            m_Mem = NULL;
        }

        if (m_Vc != NULL) {
            delete m_Vc;
            m_Vc = NULL;
        }

    }


//   提供工作函数，
    void work() {
//       让零件工作起来，调用接口。
        m_Cpu->calculate();
        m_Vc->display();
        m_Mem->storage();
    }

private:
    CPU *m_Cpu;
    VideoCard *m_Vc;
    Memory *m_Mem; // 内存条
};

//Inter 厂商
class InterCPU : public CPU {
    void calculate() {
        cout << "Inter CPU invoker " << endl;
    }
};

//Inter 厂商
class InterVideoCard : public VideoCard {
    void display() {
        cout << "Inter VideoCard invoker " << endl;
    }
};

//Inter 厂商
class InterMemory : public Memory {
    void storage() {
        cout << "Inter storage invoker " << endl;
    }
};

void test01() {
    CPU *interCPU = new InterCPU;
    VideoCard *interCard = new InterVideoCard;
    Memory *interMem = new InterMemory;

    Computer *computer = new Computer(interCPU, interCard, new InterMemory);

    computer->work();
    delete computer;

}


int main() {
    test01();
}
