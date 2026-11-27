#include <iostream>
#include <fstream>

int main(int argc, char* argv[]){

    if (argc != 2){
        std::cout << "Please give One argument" << std::endl;
        return 1;
    }
    
    std::ifstream infile;
    infile.open(argv[1]);
    
    if(!infile.is_open()){ 
        std::cout << "error opening file" << std::endl;
        return 1;
    }
/*
    std::string content;
    while(infile >> content){
        std::cout << content << std::endl;
    }
    
    infile.close();
*/

    std::string line;
    while(std::getline (infile,line)){
        std::cout << line << std::endl;
    }

    infile.close();

    return 0;
}