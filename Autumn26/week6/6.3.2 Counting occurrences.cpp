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

}

int count_occurrences(const std::vector<std::string>& text, std::string word){
    int count = 0;
    for(int i = 0; i < text.size(); i++){
        if(text[i] == word){
            count++;
        }
    }
    return count;
}


int main(){

    std::vector<std::string> text_words;
    read_words_from_file("words.txt", text_words);
    std::vector<std::string> target_words;
    read_words_from_file("target.txt", target_words);

    std::ofstream fout("output.txt");
    if(!fout){
        std::cout << "Cannot open output file." << std::endl;
        return 1;
    }
    for(int i = 0; i < target_words.size(); i++){
        int count = count_occurrences(text_words, target_words[i]);
        fout << target_words[i] << ": " << count << std::endl;
    }
    fout.close();

    return 0;
}