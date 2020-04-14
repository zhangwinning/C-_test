#include <iostream>
#include <fstream>

using namespace std;

// 文本文件 写文件
void test01() {
//   创建流对象
    ofstream ofs;
//   3. 指定打开的方式
    ofs.open("text.txt", ios::out);
//   4. 写内容
    ofs << "nama: zwn" << endl;
    ofs << "sex: boy" << endl;
    ofs << "age: 18" << endl;
//   5. 关闭文件
    ofs.close();
}

int main() {
    test01();
};