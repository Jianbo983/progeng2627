#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

int main(){
    std::ifstream infile; 
    infile.open("input.txt");

    std::vector<int> v;

    if(!infile.is_open()){ 
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    int tmp;

    while(infile >> tmp){
        v.push_back(tmp); 
        // instead of printing the values
        // as in the example above
        // first we store them in a vector
    }

    infile.close(); 

    // TODO: print the content of v in reversed order
    // onto a different text file

    std::ofstream fout("output.txt");
    if(!fout){
        std::cout << "error opening output file" << std::endl;
        return 1;
    }

    for(int i = v.size() - 1; i >= 0; i--){
        fout << v[i] << " ";
    }

    fout.close();
}