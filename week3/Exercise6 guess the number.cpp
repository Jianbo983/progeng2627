#include <iostream>

int main() {
    int low, high;

    std::cout << "Think of an integer number in some range." << std::endl;
    std::cout << "Enter the lower bound: ";
    std::cin >> low;
    std::cout << "Enter the upper bound: ";
    std::cin >> high;

    if (low > high) {
        std::cout << "Error: lower bound must be <= upper bound." << std::endl;
        return 0;
    }

    std::cout << "Then, think of an integer between "
              << low << " and " << high << " (inclusive)." << std::endl;
    std::cout << "I will try to guess it." << std::endl;
    std::cout << "After each guess, type:\n"
              << "  '>' if your number is greater than my guess,\n"
              << "  '<' if your number is less than my guess,\n"
              << "  '=' if my guess is correct.\n\n";

    int steps = 0;          // 统计猜了多少次
    bool found = false;

    while (!found && low <= high) {
        // 二分：取中间值作为猜测
        int guess = low + (high - low) / 2;
        steps++;

        std::cout << "My guess is: " << guess << ".  (>, <, =) ";
        char feedback;
        std::cin >> feedback;

        if (feedback == '=') {
            std::cout << "Great! I found your number: " << guess
                      << " in " << steps << " steps." << std::endl;
            found = true;
        } else if (feedback == '>') {
            // 说明真正的数比 guess 大：区间缩到 (guess+1 .. high)
            low = guess + 1;
        } else if (feedback == '<') {
            // 说明真正的数比 guess 小：区间缩到 (low .. guess-1)
            high = guess - 1;
        } else {
            std::cout << "Invalid input. Please type '>', '<', or '='." << std::endl;
            // 不改变区间，继续下一轮
        }
    }

    if (!found) {
        std::cout << "It seems there is some inconsistency in the answers." << std::endl;
        std::cout << "I cannot find a number that matches all your feedback." << std::endl;
    }

    return 0;
}