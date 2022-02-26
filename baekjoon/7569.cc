#include <iostream>
#include <queue>

using namespace std;

int arr[101][101][101];
bool visited[101][101][101];
int m, n, h;

int x[6] = {1, -1, 0, 0, 0, 0};
int y[6] = {0, 0, +1, -1, 0, 0};
int z[6] = {0, 0, 0, 0, 1, -1};

int counter = 1;

struct point {
  int x;
  int y;
  int z;
};

void updateCounter(int curValue) {
  if(curValue >= counter) {
    counter = curValue;
  }
}

void dfs(queue<point> &points) {
  while(!points.empty()) {
    point pos = points.front();
    points.pop();
    int prev = arr[pos.x][pos.y][pos.z];
    counter = arr[pos.x][pos.y][pos.z] > counter ? arr[pos.x][pos.y][pos.z] : counter;

    for(int i=0;i<6;i++){
      for(int j=0;j<6;j++) {
        for(int k=0;k<6;k++) {
          int newx = pos.x + x[i];
          int newy = pos.y + y[i];
          int newz = pos.z + z[i];

          if(newx >= 0 && newx < m && newy >= 0 && newy < n && newz >= 0 && newz < h) {
            if(visited[newx][newy][newz] || arr[newx][newy][newz] == -1 || arr[newx][newy][newz] == 1) continue;
            arr[newx][newy][newz] = prev + 1;
            visited[newx][newy][newz] = true;
            points.push({newx, newy, newz});
          }
        }
      }
    }
  }
}

bool checkArray() {
  for(int i=0;i<h;i++){ 
    for (int j=0;j<n;j++) {
      for(int k=0;k<m;k++){
        if(arr[k][j][i] == 0)
          return false;
      }
    }
  }
  return true;
}

void printArray() {
  for(int i=0;i<h;i++){ 
    for (int j=0;j<n;j++) {
      for(int k=0;k<m;k++){
        cout << arr[k][j][i] << " ";
      }
      cout << "\n";
    }
    cout << "\n";
  }
}

int main() {
  std:: cin >> m >> n >> h;
  queue<point> points;

  for(int i=0;i<h;i++){ 
    for (int j=0;j<n;j++) {
      for(int k=0;k<m;k++){
        cin >> arr[k][j][i];

        if(arr[k][j][i] == 1) {
          points.push(point{k, j, i});
        }
      }
    }
  }

  dfs(points);

  cout << "\n";
  printArray();

  if(!checkArray())
    cout << -1 << "\n";
  else cout << counter - 1 << "\n";
  
}