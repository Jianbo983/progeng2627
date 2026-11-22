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

bool convert_base(const std::vector<int>& input_digits, int input_base, int output_base, std::vector<int>& output_digits) {
    if (input_base < 2 || input_base > 16 || output_base < 2 || output_base > 16) {
        return false;
    }

    // Convert input digits to decimal
    int decimal_value = digits_to_decimal(input_digits, input_base);

    // Convert decimal value to output base digits
    return digits_in_base(decimal_value, output_base, output_digits);
}


int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    std::vector<int> octal_digits;
    std::vector<int> hex_digits;

    int input_base, output_base;
    std::cout << "Enter input base (2-16): ";
    std::cin >> input_base;
    std::cout << "Enter output base (2-16): ";
    std::cin >> output_base; 

    /// Obtain the octal digits of 250
    digits_in_base(num, input_base, octal_digits);

    std::cout << "First: ";
    print_digits(octal_digits);

    /// Convert the octal digits to hexadecimal digits
    if (convert_base(octal_digits, input_base, output_base, hex_digits)) {
        std::cout << "Second: ";
        print_digits(hex_digits);
    } else {
        std::cout << "Invalid base" << std::endl;
    }

    return 0;
}