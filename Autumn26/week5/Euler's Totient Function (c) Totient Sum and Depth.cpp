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

int totient_sum(int n, int &depth)
{
    int sum = 0;
    depth = 0;
    while(n > 1){
        sum += euler_totient(n);
        n = euler_totient(n);
        depth++;
    }
    return sum;
}

int main(){
    int depth;
    std::cout << "Sum: " << totient_sum(30, depth) << " Depth: " << depth << std::endl;
    std::cout << "Sum: " << totient_sum(1, depth) << " Depth: " << depth << std::endl;
    return 0;
}