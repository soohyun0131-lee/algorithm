#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:

    int processNum(const string& str, bool isMinus){
        cout << "first-processed string is " << str << ", and it's minus value is " << isMinus << endl;
        int INT_MIN = -pow(2, 31);
        int INT_MAX = pow(2, 31) - 1;

        int seedNum = 1;
        int result = 0;

        for(int i=0;i<str.length(); i++){
            

            if(isMinus){
                result -= seedNum * (str.at(i) - '0');
            }
            else{
                result += seedNum * (str.at(i) - '0');
            }

            if(result < INT_MIN){
                return INT_MIN;
            }
            else if(result >= INT_MAX){
                return INT_MAX;
            }

            seedNum *= 10;
        }
        
        return result;
    }

    int myAtoi(const string& str) {
        bool minus = false;
        bool isvalid = false;

        string temp = "";
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