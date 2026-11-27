#include <iostream>

int main(){
    int n, curmax, curmin;
    std::cout << "This program help you to find the maximum and minimum values" << std::endl;
    std::cout << "Enter numbers 0 to stop (no record of 0)" << std::endl;
    std::cout << "Now please enter number:" << std::endl;
    std::cin >> n;

    curmax = n;
    curmin = n;
    // initially the current maximum is 
    // the first number entered

    std::cout << "maximum so far: " << curmax << std::endl;
    std::cout << "minimum so far: " << curmin << std::endl;

    while(n != 0){

        std::cout << "Please enter the next number:" << std::endl;
        std::cin >> n;
        if(n == 0){
            std::cout << "maximum so far: " << curmax << std::endl;
            std::cout << "minimum so far: " << curmin << std::endl;
            return 0;
        }
        // if the current number is greater than the current max...
        if(n > curmax){
            curmax = n;
            // ...we update the current max
        }
        if(n < curmin){
            curmin = n;
            // ...we update the current min
        }
        std::cout << "maximum so far: " << curmax << std::endl;
        std::cout << "minimum so far: " << curmin << std::endl;
        // we print the current maximum and minimum in any case 
        // whether or not they were updated in this iteration of the loop
    }

}