#include <iostream>
#include <string>

void swap_text(std::string &a, std::string &b){
    std::string temp = a;
    a = b;
    b = temp;
}

int main(){
    std::string text1;
    std::string text2;

    std::cout << "Enter first text: " << std::endl;
    std::cin >> text1;
    std::cout << "Enter second text: " << std::endl;
    std::cin >> text2;

    std::cout << "Before swap: " << text1 << " " << text2 << std::endl;

    swap_text(text1, text2);

    std::cout << "After swap: " << text1 << " " << text2 << std::endl;

    return 0;
}