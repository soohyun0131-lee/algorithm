#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:

    int processNum(const string& str, bool isMinus){
        int INT_MIN = -pow(2, 31);
        int INT_MAX = pow(2, 31) - 1;

        for(int i=0;i<str.length(); i++){
            
        }
        
        cout << "first-processed string is " << str << ", and it's minus value is " << isMinus << endl;
        return 0;
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