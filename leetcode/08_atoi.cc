#include <string>
#include <iostream>
#include <cmath>

class Solution {
public:

    int32_t processNum(const std::string& str, bool isMinus){
        int32_t minVal = -2147483648;
        int32_t maxVal = 2147483647;

        int32_t seedNum = 1;
        int32_t result = 0;
        for(int32_t i=static_cast<int32_t>(str.length()) - 1;i >= 0; i--){
            if(isMinus){
                result -= seedNum * (str.at(i) - '0');
            }
            else{
                result += seedNum * (str.at(i) - '0');
            }

            if(result < minVal){
                return minVal;
            }
            else if(result >= maxVal){
                return maxVal;
            }

            seedNum *= 10;
        }
        
        return result;
    }

    int32_t myAtoi(const std::string& str) {
        bool minus = false;
        bool isvalid = false;

        std::string temp = "";
        for(char value : str){
            if(value == ' ' || value == '+'){
                continue;
            }
            else if(value == '-'){
                isvalid = true;
                minus = true;
            }
            else if(value >= '0' && value <= '9'){
                isvalid = true;
                temp += value;
            }
            else{ // any other char except characters above
                if(!isvalid){
                    return 0;
                }
                else{
                    // fin
                    return processNum(temp, minus);
                }
            }
        }
        return processNum(temp, minus);
    }
};