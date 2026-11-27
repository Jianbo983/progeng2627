#include <iostream>
#include <vector>

void filter_v(const std::vector<double>& vin, double t, std::vector<double>& vout)
{
    vout.clear();

    for(int i = 0; i < vin.size(); i++){
        if(vin[i] < t){
            vout.push_back(vin[i]);
        }
    }
}

int main(){
    std::vector<double> values;
    values.push_back(3.0);
    values.push_back(8.0);
    values.push_back(1.0);
    values.push_back(10.0);
    values.push_back(5.0);

    std::vector<double> filtered;
    filter_v(values, 5.0, filtered);

    for(int i = 0; i < filtered.size(); i++){
        std::cout << filtered[i] << " ";
    }

    std::cout << std::endl;
    return 0;
}