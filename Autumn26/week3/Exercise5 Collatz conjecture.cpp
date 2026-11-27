#include <iostream>

int main() {
    long long n; // long long 更长
    std::cout << "Enter a natural number n: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Error: n must be a natural number (n > 0)." << std::endl;
        return 0;
    }

    // 为了后面打印方便，先记住起始值
    long long start = n;

    // 统计步数
    int steps = 0;

    // 记录过程中出现的最大值
    long long maxVal = n;

    std::cout << "Collatz sequence: ";

    // 按题目要求：只打印“生成的序列”，可以从第一个变换后的数开始
    // 如果你想把起始 n 也打印出来，可以在循环前先输出 n
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }

        std::cout << n << " ";   // 打印当前 n
        steps = steps + 1;       // 步数 +1

        if (n > maxVal) {        // 更新最大值
            maxVal = n;
        }
    }

    std::cout << std::endl;

    std::cout << "Starting from " << start << ", 1 is reached in " << steps << " steps." << std::endl;
  
    std::cout << "Maximum value reached in the process: " << maxVal << std::endl;
              
    return 0;
}