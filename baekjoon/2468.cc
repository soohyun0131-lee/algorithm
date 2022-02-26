#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int n;
int arr[101][101];
bool visited[101][101];

int xpos[4] = {-1, 1, 0, 0};
int ypos[4] = {0, 0, -1, 1};

void bfs(queue<pair<int, int>> &que, int height) {
  while(!que.empty()) {
    int x = que.front().first;
    int y = que.front().second;
    que.pop();

    for(int i=0;i<4;i++){
      int newx = x + xpos[i];
      int newy = y + ypos[i];

      if(newx < 0 || newy < 0 || newx >= n || newy >= n) continue;

      if(visited[newx][newy] == false && arr[newx][newy] > height) {
        visited[newx][newy] = true;
        que.push({newx, newy});
      }
    }
  }
}

pair<int, int> findPos(int height) {
  for(int i = 0;i<n;i++) {
    for(int j=0;j<n;j++) {
      if(visited[i][j] == false && arr[i][j] > height) {
        visited[i][j] = true;
        return {i, j};
      } 
    }
  }
  return {-1, -1};
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int ans = 1;
  int maxheight = -1;

  cin >> n;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> arr[i][j];
      maxheight = maxheight > arr[i][j] ? maxheight : arr[i][j];
    }
  }

  for(int height=1;height<=maxheight;height++){
    int tmp = 0;
    queue<pair<int, int>> que;
    memset(visited, 0, sizeof(visited));

    pair<int,int> pos = {-1, -1};
    
    do {
      pos = findPos(height);
      if(pos.first >=0 && pos.second >=0) {
        tmp++;
        que.push(pos);
        bfs(que, height);
      }
    } while(pos.first != -1);
    ans = ans > tmp ? ans : tmp;
  }

  cout << ans << "\n";
}