#include <iostream>


int fact(int val) {
    int ret = 1;
    while (val > 1) {
        ret *= val--;
    }
    return ret;
}

size_t count_calls() {
    static size_t ctr = 0;      // 调用结束后，这个值依旧有效
    return ctr++;
}

int main() {
//    int j = fact(5);
//    std::cout << j << std::endl;

//    std::cout << count_calls() << std::endl;

    for(size_t i = 0; i != 10; i++) {
        std::cout << count_calls()  << std::endl;
    }
    return 0;
}