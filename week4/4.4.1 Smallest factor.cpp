#include <iostream>

int smallest_factor(int n){
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            return i;
        }
    }

    return 0;
}
void print_primes(int n, int m){
    if(n==1){
        n++;
    }
    for(int i = n; i <= m; i++){
        if(smallest_factor(i) == 0){
            std::cout << i << " ";
        }
    }
}
int main(){
    int n,m;
    std::cout << "Enter two positive integers: " << std::endl;
    std::cin >> n >> m;

    std::cout << "Primes number: ";
    print_primes(n, m);
    std::cout << std::endl;
}