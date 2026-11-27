#include <iostream>

int main() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "Error: n must be >= 0." << std::endl;
        return 0;
    }


    if (n > 20) {
        std::cout << "Warning: result will overflow long long for n > 20." << std::endl;//666原来20就撑爆了
    }



    // 用 long long 保存结果，比int存储上限更大
    long long factorial = 1;

    // 当 n = 0 时，这个循环不会执行，factorial 保持为 1，直接输出
    for (int i = n; i != 0; --i) {
        factorial = factorial * i;
    }


    std::cout << n << "! = " << factorial << std::endl;

    return 0;
}