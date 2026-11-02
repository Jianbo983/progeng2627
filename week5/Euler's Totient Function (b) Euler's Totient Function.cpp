#include <iostream>

int gcd(int a, int b)
{
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}


int euler_totient(int n)
{
    int x=0;
    for(int i=1; i<=n; i++){
        if(gcd(i, n) == 1){
            x++;
        }
    }
    return x;
}

int main(){
    std::cout << euler_totient(9) << std::endl;
    std::cout << euler_totient(12) << std::endl;
    std::cout << euler_totient(17) << std::endl;
    std::cout << euler_totient(1) << std::endl;
    return 0;
}