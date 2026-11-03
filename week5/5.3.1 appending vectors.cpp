#include <iostream>
#include <vector>

std::vector<int> append_vectors(const std::vector<int>& a, const std::vector<int>& b){
    std::vector<int> result = a;

    for(int i = 0; i < b.size(); i++){
        result.push_back(b[i]);
    }

    return result;
}

int main(){
    std::vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    std::vector<int> b;
    b.push_back(-7);
    b.push_back(-8);

    std::vector<int> c = append_vectors(a, b);

    for(int i = 0; i < c.size(); i++){
        std::cout << c[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}