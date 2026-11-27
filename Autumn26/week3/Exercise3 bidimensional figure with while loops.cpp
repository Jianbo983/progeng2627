#include <iostream>

int main() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    int row = 0;                 // 控制行数：已经画了多少行
    while (row < n) {            // 画 n 行

        int col = 0;             // 控制列数：当前行已经画了多少个 *
        while (col < n) {        // 每行画 n 个 *
            std::cout << "*";
            col = col + 1;       // 相当于 col++
        }

        std::cout << std::endl;  // 一行结束后换行
        row = row + 1;           // 相当于 row++
    }

    return 0;
}