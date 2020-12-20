#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct ST {
    int index;
    int start; int end;
    
    ST(){
        start = end = 0;
        index = -1;
    }
    
    ST(int st, int en, int id){
        index = id;
        start = st; end = en;
    }
};

bool mysort(ST &a, ST &b){
    return a.start < b.start;
}

int main(){
    int TC;
    std::cin >> TC;
    
    for(int tc=1;tc<=TC;tc++){
        string ans = "";
        
        int cend = 0;
        int jend = 0;
        bool impossible = false;
        
        int subcase = 0;
        std::cin >> subcase;
        
        vector<ST> stvec;
        vector<string> pos(subcase);
        
        for(int i=0;i<subcase;i++){
            int st = 0; int end = 0;
            
            std::cin >> st >> end;
            ST tmp = ST(st, end, i);         
            stvec.push_back(tmp);
        }
        
        sort(stvec.begin(), stvec.end(), mysort);
        
        pos[stvec[0].index] = "C";
        cend = stvec[0].end;
        pos[stvec[1].index] = "J";
        jend = stvec[1].end;
        
        for(int i=2;i<stvec.size();i++){
            if(stvec[i].start >= cend){
                pos[stvec[i].index] = "C";
                cend = stvec[i].end;
            }
            else if(stvec[i].start >= jend){
                pos[stvec[i].index] = "J";
                jend = stvec[i].end;
            }
            else{
                impossible = true;
                break;
            }
        }
        
        
        if(impossible) ans = "IMPOSSIBLE";
        else{
            for(int i=0;i<stvec.size();i++){
                ans += pos[i];
            }
        }
        std::cout << "Case #" << tc << ": " << ans << std::endl;
        //std::cout << endl;
    }
}