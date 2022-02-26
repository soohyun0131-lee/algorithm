#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int tomato[1001][1001];
int x[4] = {0, 0, -1, 1};
int y[4] = {-1, 1, 0, 0};

bool isAllRipened(int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(tomato[i][j] == 0) return false;
        }
    }   
    return true;
}

int main() {
    int m, n;
    int counter = 1;
    queue<pair<int, int>> points;
    
    cin >> m >> n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            std::cin >> tomato[i][j];
            if(tomato[i][j] == 1)
                points.push(make_pair(i,j));
        }
    }
    
    // do dfs
    while(!points.empty()) {
        pair<int, int> point = points.front();
        int prev = tomato[point.first][point.second];
        counter = prev > counter? prev : counter;

        points.pop();
        
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                int new_x = point.first + x[i];
                int new_y = point.second + y[i];
                
                if(new_x >= 0 && new_y >= 0 && new_x < n && new_y < m && tomato[new_x][new_y] == 0) {
                  tomato[new_x][new_y] = prev + 1;
                  points.push(make_pair(new_x,new_y));
                }
            }
        }
    }
    
    if(isAllRipened(n, m)) cout << counter - 1 << std:: endl;
    else cout << -1 << std:: endl;;
}