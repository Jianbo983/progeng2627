#include <iostream>

double max_of_two(double a, double b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

int main(){
    double x, y;
    std::cout << "please enter two numbers" << std::endl;
    std::cin >> x >> y;

    std::cout << "maximum: " << max_of_two(x, y) << std::endl;
}