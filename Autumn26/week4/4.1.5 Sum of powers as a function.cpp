#include <iostream>

double mypow(double base, int exp){ //找出每一项的次方
    double result = 1.0;

    for(int i = 0; i < exp; i++){
        result = result * base;
    }

    return result;
}

double sum_of_powers(double x, int n){ //把所有项相加
    double sum = 0.0;

    for(int i = 0; i <= n; i++){
        sum = sum + mypow(x, i);
    }

    return sum;
}

int main(){
    double x;
    int n;

    std::cout << "please enter x and n" << std::endl;
    std::cin >> x >> n;

    if(n < 0){
        std::cout << "Error: exponent must be non-negative." << std::endl;
        return 1;
    }

    std::cout << "sum of powers: " << sum_of_powers(x, n) << std::endl;

    return 0;
}