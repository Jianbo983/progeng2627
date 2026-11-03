#include <iostream>
#include <vector>

int search_vector(int n, const std::vector<int>& vin)
{
    for (int i = 0; i < vin.size(); ++i)
    {
        if (vin[i] == n)
        {
            return i;
        }
    }
    return -1;
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

    std::cout << "Enter a value to search for: " << std::endl;
    int value;
    std::cin >> value;
    int index = search_vector(value, values);
    std::cout << "The index of the value is: " << index << std::endl;
    if (index == -1){
        std::cout << "Value not found in the vector." << std::endl;
    }
    return 0;
}