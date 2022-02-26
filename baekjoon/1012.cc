#include <iostream>
#include <memory.h>
#include <queue>
#include <list>

using namespace std;

int arr[51][51];
int visited[51][51];
int m, n, k;

int xpos[4] = {0, 0, -1, 1};
int ypos[4] = {-1, 1, 0, 0};

void bfs(queue<pair<int,int>> &farm) {
  while(!farm.empty()) {
    int x = farm.front().second;
    int y = farm.front().first;
    farm.pop();

    for(int i=0;i<4;i++) {
      int new_x = x + xpos[i];
      int new_y = y + ypos[i];

      if(new_x <= m && new_y <= n && new_x >=0 && new_y >= 0) {
        if(arr[new_y][new_x] == 1 && visited[new_y][new_x] == false) {
          visited[new_y][new_x] = true;
          farm.push(make_pair(new_y, new_x));  
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int x, y;
  int testcase;

  cin >> testcase;

  for(int tc = 0; tc < testcase; tc++){
    queue<pair<int, int>> farm;
    list<pair<int,int>> candidates;
    int ans = 0;

    memset(arr, 0, sizeof(arr));
    memset(visited, 0, sizeof(visited));

    cin >> m >> n >> k;
    //std::cout << "k is " << k << "\n";

    for(int i=0;i<k;i++) {
      cin >> x >> y;
      arr[y][x] = 1;
      candidates.push_back(make_pair(y, x));
    }

    //cout << "candidate size is " << candidates.size() << "\n";

    while(!candidates.empty()){
      int tmpY = candidates.front().first;
      int tmpX = candidates.front().second;
      candidates.pop_front();
      //cout << "candidate is " << tmpX << ", " << tmpY << "\n";
      //cout << "visited is " << visited[tmpY][tmpX] << "\n";

      if(arr[tmpY][tmpX] == 1 && visited[tmpY][tmpX] == false) {
        //cout << "ans will be plused\n";
        ans++;
        visited[tmpY][tmpX] = true;
        farm.push(make_pair(tmpY, tmpX));
        bfs(farm);
      }
    }

    cout << ans << "\n";

  }
  return 0;
}