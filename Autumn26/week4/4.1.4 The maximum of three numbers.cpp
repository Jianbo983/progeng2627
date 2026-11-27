#include <iostream>

double max_of_three(double a, double b, double c){
    if(a >= b && a >= c){
        return a;
    }
    else if(b >= a && b >= c){
        return b;
    }
    else{
        return c;
    }
}

int main(){
    double x, y, z;
    std::cout << "please enter three numbers" << std::endl;
    std::cin >> x >> y >> z;

    std::cout << "maximum: " << max_of_three(x, y, z) << std::endl;
}