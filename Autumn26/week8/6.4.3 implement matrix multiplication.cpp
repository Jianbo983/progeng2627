#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include <sstream>

#include <iomanip>



std::vector<double> line_to_vector(std::string s){

    std::stringstream ss;  
    std::string tmp;
    std::vector<double> out;

    ss << s;
    while(ss >> tmp){
        out.push_back(std::stod(tmp));
    }
    return out;
}

std::vector<std::vector<double>> read_matrix_from_file(std::string input_file){

    std::ifstream infile;
    infile.open(input_file);
    if(!infile.is_open()){
        std::cout << "error opening file " << input_file << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::string line;
    std::vector<std::vector<double>> out;

    while(std::getline(infile, line)){
        out.push_back(line_to_vector(line));
    }

    return out;
}

std::string matrix_to_string(std::vector<std::vector<double>> m){

    std::stringstream out;
    out << std::fixed << std::setprecision(2);

    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m[0].size(); j++){
            out << (m[i][j]) << "\t";
        }
        out << "\n";
    }

    return out.str();
}





std::vector<double> get_column(const std::vector<std::vector<double>>& m1, int n){//找列，找行不需要
    std::vector<double> column;
    for(int i=0; i<m1.size(); i++){
        column.push_back(m1[i][n]);
    }
    return column;
}

double scalar_product(const std::vector<std::vector<double>>& m1, const std::vector<std::vector<double>>& m2, int x, int y){
    std::vector<double> row = m1[x];
    std::vector<double> column = get_column(m2, y);
    double out = 0;
    for(int i=0; i<m1[x].size(); i++){
        out = out + row[i] * column[i];
    }
    return out;
}



int main(int argc, char* argv[]){
    if(argc != 3){
    std::cout << "two arguments needed" << std::endl;
    return EXIT_FAILURE;
    }

    std::vector<std::vector<double>> m1 = read_matrix_from_file(argv[1]);
    std::vector<std::vector<double>> m2 = read_matrix_from_file(argv[2]);

    std::vector<std::vector<double>> m3;
    for(int i=0; i<m1.size(); i++){
        std::vector<double> row;
        for(int j=0; j<m2[0].size(); j++){
        row.push_back(scalar_product(m1, m2, i, j));
        }
        m3.push_back(row);
    }
    std::cout << matrix_to_string(m1) << std::endl;
    std::cout << "*" << std::endl << std::endl;
    std::cout << matrix_to_string(m2) << std::endl;
    std::cout << "=" << std::endl << std::endl;
    std::cout << matrix_to_string(m3) << std::endl;

    return 0;
}