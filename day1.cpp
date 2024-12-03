#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

long computeDist(std::vector<int>& first, std::vector<int>& second) {
        long output = 0;
        for(int i = 0; i < first.size(); i++){
                output += abs(first[i]-second[i]);
        }
        return output;
}

long computeSimilarity(std::vector<int>& first, std::unordered_map<int,int>& freq) {
        int output = 0;
        for(auto num: first){
                if(freq.find(num) != freq.end()){
                        output += num*freq[num];
                }
        }
        return output;
}

int main() {
        std::ifstream file("in.txt");
        if(!file){
                std::cerr << "Could not find/open the file" << std::endl;
                return 1;
        }
        std::vector<int> first, second;
        std::string line;
        std::unordered_map<int,int> freq;

        while(std::getline(file,line)) {
                std::istringstream stream(line);
                int val1, val2;
                if(stream >> val1 >> val2) {
                        first.push_back(val1);
                        second.push_back(val2);
                        freq[val2]++;
                }
        }

        if(first.size() != second.size()){
                return 1;
        }

        file.close();
        std::sort(first.begin(), first.end());
        std::sort(second.begin(), second.end());
        std::cout << "Distance: " << computeDist(first, second) << std::endl;
        std::cout << "Similarity: " << computeSimilarity(first,freq) << std::endl;
        return 0;
}
