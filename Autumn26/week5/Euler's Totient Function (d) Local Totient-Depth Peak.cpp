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
        n = euler_totient(n);
        sum = sum + n;
        depth++;
    }
    return sum;
}

bool is_peak(int n){
    int left_depth, mid_depth, right_depth;

    totient_sum(n - 1, left_depth);
    totient_sum(n, mid_depth);
    totient_sum(n + 1, right_depth);

    return mid_depth > left_depth && mid_depth > right_depth;
}

int peak_strength(int n){
    int depth;
    totient_sum(n, depth);
    return depth;
}

int main(){
    int a,b;
    int left_depth = 0, mid_depth = 0, right_depth = 0;
    std::cout << "Enter the range (a b): ";
    std::cin >> a >> b;
    int peak, best_peak=-1;
    int best_strength = -1;
    for(int i = a+1; i <= b-1; i++){
        if(is_peak(i)){
            peak = i;
            if(peak_strength(peak) > peak_strength(best_peak)||peak_strength(peak) == peak_strength(best_peak) && peak < best_peak){
                best_peak = peak;
                best_strength = peak_strength(best_peak);

                totient_sum(best_peak - 1, left_depth);
                totient_sum(best_peak, mid_depth);
                totient_sum(best_peak + 1, right_depth);
            }
        }
    }
    std::cout << "Best peak: " << best_peak << std::endl;
    std::cout << "Peak strength: " << best_strength << std::endl;
    std::cout << "Depth(x-1): " << left_depth << std::endl;
    std::cout << "Depth(x): " << mid_depth << std::endl;
    std::cout << "Depth(x+1): " << right_depth << std::endl;
}