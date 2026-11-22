#include <iostream>
#include <fstream>
#include <vector>

void read_words_from_file(const std::string& filename, std::vector<std::string>& words){
    std::ifstream infile; 
    infile.open(filename);
    std::string tmp;

      if(!infile.is_open()){ 
        std::cout << "error opening file" << std::endl;
        return;
    }
        while(infile >> tmp){
        words.push_back(tmp); 
    }
    infile.close();
}

void divide_words(const std::vector<std::string>& text, std::vector<std::string>& origin, std::vector<std::string>& target){
    for(int i = 0; i < text.size(); i++){
        if(i%2 == 0){
            origin.push_back(text[i]);
        }
        else{
            target.push_back(text[i]);
        }
        
    }
}


int main(){
    std::vector<std::string> text_words;
    read_words_from_file("advertisement.txt", text_words);
    std::vector<std::string> real_meaning, origin_words, target_words;
    read_words_from_file("real meaning.txt", real_meaning);
    divide_words(real_meaning, origin_words, target_words);

    std::ofstream fout("output.txt");
     if(!fout){
        std::cout << "Cannot open output file." << std::endl;
        return 1;
    }

    
    for(int i=0; i < text_words.size(); i++){
        bool found = false;
        for(int j=0; j < origin_words.size(); j++){
            if(text_words[i]==origin_words[j]){
                fout << target_words[j] << " ";
                found = true;
                break;
            }
        }
        if(found == false){
            fout << text_words[i] << " ";
        }
    }

    return 0;
}