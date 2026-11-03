#include <iostream>
#include <vector>

int min_vector_element(const std::vector<double>& vin) {
    int min_index = 0;
    if (vin.empty()) {
        return -1; 
    }
    for (int i = 1; i < vin.size(); i++) {
        if (vin[i] < vin[min_index]) {
            min_index = i;
        }
    }
    return min_index;
}


int main(){
    std::vector<double> values;
    values.push_back(9.0);
    values.push_back(7.0);
    values.push_back(5.0);
    values.push_back(1.0);
    values.push_back(2.0);
    std::cout << min_vector_element(values) << std::endl;

    return 0;
}