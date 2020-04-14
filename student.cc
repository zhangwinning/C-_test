#include <string>
#include <iostream>

using std::string;

class Student {
public:

//   类中的属性和行为都称为 成员
//   属性 成员属性
//   行为 成员函数  成员方法
    string name;
    int dep;


    void setName(string name1) {
        name = name1;
    };

    void setId(int id) {
        dep = id;
    }

    void show() {
        std::cout << name << " " << dep << std::endl;
    }
};

int main() {
    Student s1;
    s1.setName("张三");
    s1.setId(1000);

//    Student s2;
//    s2.name = "李四";
//    s2.dep = 200;

    s1.show();
//    s2.show();
}