#include <iostream>
#include <string>
#include <queue>

using namespace std;

char origin[4][4];
char wanted[4][4];
char visited[4][4];

int ipos[4] = {-1, 1, 0, 0};
int jpos[4] = {0, 0, -1, 1};

void bfs(queue<pair<int, int>> &line) {
  while(!line.empty()) {
    int x = line.front().first;
    int y = line.front().second;
    line.pop();

    for(int i=0;i<4;i++){
      int newi = x + ipos[i];
      int newj = y + jpos[i];

      if(newi >=0 && newj >= 0 && newi < 4 && newj < 4) {
        if(origin[newi][newj] != wanted[newi][newj] && origin[newi][newj] == wanted[x][y]) {
          char tmp = origin[newi][newj];
          origin[newi][newj] = origin[x][y];
          origin[x][y] = tmp;
        }
      }
    }
  }

}

int main() {
  string str;
  queue<pair<int,int>> line;
  int ans = 0;

  for(int i=0;i<4;i++) {
    cin >> str;
    for(int j=0;j<4;j++) {
      origin[i][j] = str[j];
    }
  }

  for(int i=0;i<4;i++) {
    cin >> str;
    for(int j=0;j<4;j++) {
      wanted[i][j] = str[j];
    }
  }

  for(int i=0;i<4;i++) {
    for(int j=0;j<4;j++){
      if(origin[i][j] != wanted[i][j]) {
        ans++;
        line.push(make_pair(i, j));
        bfs(line);
      }
    }
  }

  cout << ans << "\n";
}