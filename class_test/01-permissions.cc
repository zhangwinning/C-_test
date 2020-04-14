#include <iostream>

using namespace std;

/**
 * 访问权限 public 成员类内可以访问，类外也可以访问
 * 保护权限 protected 类内可以访问，类外不可以访问。儿子可以访问父亲中的保护内容
 * 私有权限 private   类内可以访问，类外不可访问。  儿子不可访问父亲中的私有内容
 * @return
 */

class Person {
public:
    string m_Name;

protected:
    string m_Car;

private:
    int m_Password;

public:
    void setName(string name) {
        m_Name = name;
    }

    void setCar(string car) {
        m_Car = car;
    }

    void setPassword(int password) {
        m_Password = password;
    }

    void show() {
        std::cout << m_Name << " " << m_Car << " " << m_Password << " " << std::endl;
    }
};

int main() {
    Person p1;
//    p1.m_Name = "李四";
//    p1.m_Password = 111;
    p1.setName("张三");
    p1.setCar("奔驰");
    p1.setPassword(100);

    p1.show();
}