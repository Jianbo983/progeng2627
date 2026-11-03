#include <iostream>
#include <vector>

std::vector<int> filter_values(std::vector<int> values, int t){
    std::vector<int> result;

    for(int i = 0; i < values.size(); i++){
        if(values[i] < t){
            result.push_back(values[i]);
        }
    }

    return result;
}

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

    std::cout << "Enter the threshold value: " << std::endl;
    int t;
    std::cin >> t;

    
    std::vector<int> filtered = filter_values(values, t);

    std::cout << "Filtered values less than " << t << ": " << std::endl;
    for(int i = 0; i < filtered.size(); i++){
        std::cout << filtered[i] << " ";
    }

    return 0;
}