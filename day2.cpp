#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

bool isIncreasing(const std::vector<int>& nums){
        bool tolerate = false;
        for(int i = 1; i < nums.size(); i++){
                int diff = nums[i]-nums[i-1];
                if(diff > 3 || diff <= 0){
                        return false;
                }
        }
        return true;
}

bool isDecreasing(const std::vector<int>& nums){
        bool tolerate = false;
        for(int i = 1; i < nums.size(); i++){
                int diff = nums[i]-nums[i-1];
                if(diff < -3 || diff >= 0){
                        return false;
                }
        }
        return true;
}


bool isSafeWithDampener(const std::vector<int>& nums){
        if(isIncreasing(nums) || isDecreasing(nums)){
                return true;
        }

        for(int i = 0; i < nums.size(); i++){
                std::vector<int> modified = nums;
                modified.erase(modified.begin()+i);
                if(isIncreasing(modified) || isDecreasing(modified)){
                        return true;
                }
        }
        return false;
}


int main() {
        std::ifstream file("in.txt");
        if(!file){
                std::cerr << "Could not find/open the file" << std::endl;
                return 4;
        }

        std::string line;
        int output = 0;
        int outputDampener = 0;

        while(std::getline(file,line)) {
                std::istringstream stream(line);
                std::vector<int> vec;
                int num;
                while(stream >> num){
                        vec.push_back(num);
                }
                if(isIncreasing(vec) || isDecreasing(vec)){
                        // std::cout << "SAFE" << std::endl;
                        output++;
                } else {
                        // std::cout << "UNSAFE" << std::endl;
                }
                if(isSafeWithDampener(vec)){
                        outputDampener++;
                }
        }

        std::cout << "Number of Safe reports: " << output << std::endl;
        std::cout << "Number of Safe reports with Dampener: " << outputDampener << std::endl;

        return 0;
}
