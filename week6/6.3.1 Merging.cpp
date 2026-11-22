#include <iostream>
#include <vector>

void merge_vectors_int(const std::vector<int>& v1, const std::vector<int>& v2, std::vector<int>& merged){
    merged.clear();
    int i = 0, j = 0;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] <v2[j]){
            merged.push_back(v1[i]);
            i++;
        }
        else{
            merged.push_back(v2[j]);
            j++;
        }
    }
    if(i == v1.size()){
        for(int k = j; k < v2.size(); k++){
            merged.push_back(v2[k]);
        }
    }
    else{
        for(int k = i; k < v1.size(); k++){
            merged.push_back(v1[k]);
        }
    }
}


int main(){

    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> out;

    std::vector<int> expected_output;

    v1 = {1, 3, 5, 6};
    v2 = {4, 6, 10};
    expected_output = {1, 3, 4, 5, 6, 6, 10};

    merge_vectors_int(v1, v2, out);

    if(out == expected_output){ // we can compare the content of vectors (at least in some cases)
        std::cout << "passed" << std::endl;
    }
    else{
        std::cout << "not passed" << std::endl;
    }
}