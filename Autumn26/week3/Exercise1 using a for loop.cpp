#include <iostream>

int main() {
    double x;      // 底数 x，可以是小数
    int n;         // 指数 n，要求 n >= 0

    std::cout << "Enter x: ";
    std::cin >> x;

    std::cout << "Enter n: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "Error: n must be >= 0." << std::endl;
        return 0;
    }

    double result = 1.0;  // 从1开始累乘

    // 用for循环做n次乘法：result = x * x * ... * x
    for (int i = 0; i < n; ++i) {
        result = result * x;
    }

    std::cout << x << "^" << n << " = " << result << std::endl;

    return 0;
}