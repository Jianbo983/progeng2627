#include <iostream>
#include <vector>

bool digits_in_base(int num, int base, std::vector<int>& digits){
    if(base < 2 || base > 16){
        return false;
    }

    digits.clear();

    if(num == 0){
        digits.push_back(0);
        return true;
    }

    std::vector<int> remainders;

    while(num > 0){
        remainders.push_back(num % base);
        num = num / base;
    }

    for(int i = remainders.size() - 1; i >= 0; i--){
        digits.push_back(remainders[i]);
    }

    return true;
}

void print_digits(const std::vector<int>& digits){
    for(int i = 0; i < digits.size(); i++){
        if(digits[i] < 10){
            std::cout << digits[i];
        }
        else{
            std::cout << char('A' + digits[i] - 10);
        }
    }
    std::cout << std::endl;
}


int digits_to_decimal(const std::vector<int>& digits, int base){
    int value = 0;
    for(int i = 0; i < digits.size(); i++){
        value = value * base + digits[i];
    }
    return value;
}


int main(){
    int num = 250;
    int base = 16;
    std::vector<int> digits;

    if(digits_in_base(num, base, digits)){
        print_digits(digits);
        int decimal = digits_to_decimal(digits, base);
        std::cout << "Decimal number restored from digits: " << decimal << std::endl;
    } else {
        std::cout << "Invalid base" << std::endl;
    }

    return 0;
}