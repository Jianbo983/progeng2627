#include <iostream>

int main() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Error: n must be > 0." << std::endl;
        return 0;
    }

    // 外层循环控制“行”
    for (int i = 1; i <= n; ++i) {
        // 内层循环控制“列”
        for (int j = 1; j <= n; ++j) {
            std::cout << i * j << "\t";  // 打印 i*j，然后一个制表符
        }
        std::cout << std::endl;          // 每行结束后换行
    }

    return 0;
}