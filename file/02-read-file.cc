#include <iostream>
// all standard library definitions are inside the namespace std.
#include <fstream>

using namespace std;

//文本文件的读取
void test01() {
    ifstream ifs;

// 打开文件，并且判断是否打开成功
    ifs.open("text.txt", ios::in);

//   4.是否打开成功
    if (!ifs.is_open()) {
        cout << "打开文件失败" << endl;
        return;
    }

//  方式一读数据
//    char buf[1024] = {0};
//    while (ifs >> buf) {
//        cout << buf << endl;
//    }
////  方式二读取文件
//    char buf[1024] = {0};
//    while (ifs.getline(buf, sizeof(buf))) {
//        cout << buf << endl;
//    }
//  方式三: 使用全局的 getline
    string buf;
    while (getline(ifs, buf)) {
        cout << buf << endl;
    }

//  5、关闭文件
    ifs.close();
}

int main() {
    test01();
}
