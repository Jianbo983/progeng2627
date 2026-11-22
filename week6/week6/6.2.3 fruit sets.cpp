#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

int search_vector(std::string s, const std::vector<std::string>& vin){
    for(int i = 0; i < vin.size(); i++){
        if(vin[i] == s){
            return i;
        }
    }
    return -1;
}

void union_vector(const std::vector<std::string>& vin1,
                  const std::vector<std::string>& vin2,
                  std::vector<std::string>& vout){
    vout.clear();

    for(int i = 0; i < vin1.size(); i++){
        if(search_vector(vin1[i], vout) == -1){
            vout.push_back(vin1[i]);
        }
    }

    for(int i = 0; i < vin2.size(); i++){
        if(search_vector(vin2[i], vout) == -1){
            vout.push_back(vin2[i]);
        }
    }
}

void intersection_vector(const std::vector<std::string>& vin1,
                         const std::vector<std::string>& vin2,
                         std::vector<std::string>& vout){
    vout.clear();

    for(int i = 0; i < vin1.size(); i++){
        if(search_vector(vin1[i], vin2) != -1 &&
           search_vector(vin1[i], vout) == -1){
            vout.push_back(vin1[i]);
        }
    }
}

int main(){
    std::string file1name, file2name;
    std::cout << "Enter first input file name: " << std::endl;
    std::cin >> file1name;
    std::cout << "Enter second input file name: " << std::endl;
    std::cin >> file2name;

    std::ifstream file1(file1name);
    std::ifstream file2(file2name);

    if(!file1 || !file2){
        std::cout << "Error opening input files." << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<std::string> warehouse1, warehouse2;
    std::string fruit;

    while(file1 >> fruit){
        warehouse1.push_back(fruit);
    }

    while(file2 >> fruit){
        warehouse2.push_back(fruit);
    }

    file1.close();
    file2.close();

    std::vector<std::string> union_result, intersection_result;

    union_vector(warehouse1, warehouse2, union_result);
    intersection_vector(warehouse1, warehouse2, intersection_result);


    
    std::ofstream union_file("union.txt");
    std::ofstream intersection_file("intersection.txt");

    if(!union_file || !intersection_file){
        std::cout << "Error opening output files." << std::endl;
        return EXIT_FAILURE;
    }

    for(int i = 0; i < union_result.size(); i++){
        union_file << union_result[i] << std::endl;
    }

    for(int i = 0; i < intersection_result.size(); i++){
        intersection_file << intersection_result[i] << std::endl;
    }

    union_file.close();
    intersection_file.close();

    return 0;
}