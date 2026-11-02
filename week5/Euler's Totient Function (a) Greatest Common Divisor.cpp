#include <iostream>

/*
int gcd(int a, int b){
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}
*/

int gcd(int a, int b)
{
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

int main(){
    std::cout << gcd(12, 18) << std::endl;
    std::cout << gcd(48, 18) << std::endl;
    std::cout << gcd(7, 13) << std::endl;

    return 0;
}