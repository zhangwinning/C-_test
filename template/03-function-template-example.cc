/**
 * 函数模板案例
**/

#include <iostream>

using namespace std;

template<class T>
void mySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// 排序数组
template<class T>
void mySort(T arr[], int len) {
    for (int i = 0; i < len; i++) {
        int min = i;    // 认定最小值
        for (int j = i + 1; j < len; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }

        if (min != i) {
//           交换 max 和 i 下标的逻辑
            mySwap(arr[min], arr[i]);
        }
    }
}

template<class T>
void print(T arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test01() {
    char charArr[] = "asdfghjklbc";
    int len = sizeof(charArr) / sizeof(char);
    mySort<char>(charArr, len);
    print<char>(charArr, len);

    int numberArr[] = {10, 0, 9, 6, 43, 3, 2, 7, 8, 9, 1, 2, 3, 1, 2, 3, 4,};
    int lenNum = sizeof(numberArr) / sizeof(int);
    mySort<int>(numberArr, lenNum);
    print<int>(numberArr, lenNum);
}

int main() {
    test01();
}