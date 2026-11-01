#include <iostream>

void integer_division(int a, int b, int& quotient, int& remainder){
    quotient = a / b;
    remainder = a % b;
}

int main(){
    int a, b;
    int q, r;

    std::cout << "Enter two integers a and b: " << std::endl;
    std::cin >> a >> b;

    integer_division(a, b, q, r);

    std::cout << "Quotient: " << q << std::endl;
    std::cout << "Remainder: " << r << std::endl;

    return 0;
}