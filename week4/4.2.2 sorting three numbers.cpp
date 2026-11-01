#include <iostream>

void swap_numbers(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

void sort_three(int &a, int &b, int &c){
    if(a > b){
        swap_numbers(a, b);
    }

    if(b > c){
        swap_numbers(b, c);
    }

    if(a > b){
        swap_numbers(a, b);
    }
}


int main(){
    int a, b, c;
    std::cout << "please enter three numbers" << std::endl;
    std::cin >> a >> b >> c;

    sort_three(a, b, c);

    std::cout << "sorted order: "
              << a << " " << b << " " << c << std::endl;

    return 0;
}