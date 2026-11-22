#include <iostream>
#include <string>
#include <vector>
#include <utility>

std::string char_to_string(char c){
    std::string s;
    s.push_back(c);
    return s;
}

bool is_palindrome(std::string s){
    int j=s.size() - 1;
    for(int i = 0; i < s.size() - 1; i++){
        if(s[i] == ' '){
            i++;
        }
        if(s[j] == ' '){
            j--;
        }
        if(s[i] != s[j]){
            return false;
        }
        j--;
    }
    return true;
}

int main(){

    std::vector<std::pair<std::string, bool>> test_cases = 
    {
        {"a man a plan a canal panama", true}, 
        {"a man plan a canal panama", false},
        {"a toyota", true},
        {"never odd or even", true},
        {"never even or odd", false}
    };

    for(int i = 0; i < test_cases.size(); i++){
        bool test = is_palindrome(test_cases[i].first);

        if(test == test_cases[i].second){
            std::cout << "passed" << std::endl;
            std::cout << std::endl;
        }
        else{
            std::cout << "FAILED" << std::endl;
            std::cout << test_cases[i].first << std::endl;
            std::cout << "expected: " << test_cases[i].second << std::endl;
            std::cout << "got: " << test << std::endl;
            std::cout << std::endl;
        }
    }
}