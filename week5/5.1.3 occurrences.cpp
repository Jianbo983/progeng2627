#include <iostream>
#include <vector>

int main(){
    std::vector<int> values;
    int size;
    std::cout << "Number of elements in the vector: " << std::endl;
    std::cin >> size;

    for(int i = 0; i < size; i++){
        int value;
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> value;
        values.push_back(value);
    }

    std::cout << "Enter a value: " << std::endl;
    int t;
    std::cin >> t;

    int count = 0;
    for(int i = 0; i < values.size(); i++){
        if(values[i] == t){
            count++;
        }
    }
    if (count == 0){
        std::cout << "There are no occurrences of " << t << " in the vector." << std::endl;
    } else {
        std::cout << "There are " << count << " occurrences of " << t << " in the vector." << std::endl;
    }
    
    return 0;
}