#include <iostream>

int main() {
    long long n, num;
    std::cout << "please enter an integer greater than 1" << std::endl;
    std::cin >> n;

    if (n <= 1) {
        std::cout << "the number is not prime" << std::endl;
        return 0;
    }

    bool found_factor = false;

    // 改进点 1：条件里加 found_factor == false
    // 改进点 2：只检查到 sqrt(n)，用 cf * cf <= n
    for (long long cf = 2; (cf * cf <= n) && (found_factor == false); ++cf) {
        if (n % cf == 0) {
            found_factor = true;
            num = cf;
        }
    }

    if (found_factor) {
        std::cout << "the number is not prime, it can be divided by " << num << std::endl;
    } else {
        std::cout << "the number is prime" << std::endl;
    }

    return 0;
}