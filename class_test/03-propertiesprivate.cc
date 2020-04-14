#include <iostream>

using namespace std;

class Person {
public:
    string getName() {
        return name;
    }

    void setName(string name1) {
        name = name1;
    }

    int getAge() {
        m_Age = 10;
        return m_Age;
    }

private:
    string name;
    int m_Age;
    string m_Lover;
};

int main() {
    Person p;
    p.setName("zhangsan");
    cout << p.getName() << endl;

    cout << p.getAge() << endl;
    return 0;
}