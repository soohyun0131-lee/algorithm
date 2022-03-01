#include <iostream>
#include <stdio.h>		
#include <string>
#include <queue>

using namespace std;

int N;
int M;
int K;

struct arrInfo {
  int x;
  int y;
  int dir;
  int keepPos;
  int cnt;
};

int ans = 987654321;

int x1, y1, x2, y2;
queue<arrInfo> pos;

char arr[1001][1001];
bool visited[4][1001][1001];

int xpos[4] = {-1, 1, 0, 0};
int ypos[4] = {0, 0, -1, 1};

void bfs() {
  while(!pos.empty()) {
    arrInfo curPos = pos.front();
    cout << "curPos is " << curPos.x << " " << curPos.y << "\n";
    std::cout << "dir, keepPos, cnt is " << curPos.dir << " " << curPos.keepPos << " " << curPos.cnt << "\n";
    pos.pop();

    if(curPos.x == x2 && curPos.y == y2) {
      //std::cout << "finally arrived!\n";
      ans = min(ans, curPos.cnt);
      return;
    }

    for(int i=0;i<4;i++) {
      int nextX = curPos.x + xpos[i];
      int nextY = curPos.y + ypos[i];
      int nextKeepPos = 1;
      int cnt = curPos.cnt;

      if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= M || visited[i][nextX][nextY] == true || arr[nextX][nextY] == '#') {
        continue;
      }
        
      visited[i][nextX][nextY] = true;

      if(i == curPos.dir) {
        nextKeepPos = curPos.keepPos + 1;
        if(nextKeepPos >= K) {
          nextKeepPos = 0;
          cnt++;
        }
        pos.push({nextX, nextY, i, nextKeepPos, cnt});
      }
      else {
        pos.push({nextX, nextY, i, nextKeepPos, cnt+1});
      }
    }
  }
}

int min(int a, int b) {
  return a > b? b : a;
}

int main() {
  cin >> N >> M >> K;

  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      scanf("%1s", &arr[i][j]);
    }
  }

  cin >> x1 >> y1 >> x2 >> y2;
  x1--; y1--;x2--;y2--;

  for(int i=0;i<4;i++) {
      visited[i][x1][y1] = true;
  pos.push({x1, y1, i, 0, 0});
  }
  bfs();
  
  if(ans == 987654321)
    cout << "-1\n";
  else cout << ans << "\n";
}