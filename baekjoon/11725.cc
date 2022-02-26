#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;

int parents[100002];
vector<int> graphs[100002];

struct clues {
  bool isParent;
  int nodeNumber;
};

void bfs(int parent, int current) {
  vector<int> next = graphs[current];

  parents[current] = parent;

  for(int i=0;i<next.size();i++) {
      if(next[i] == parent) continue;
      bfs(current, next[i]);
  }
}

int main() {
  int a, b;
  cin >> N;

  for(int i=0;i<N-1;i++) {
    cin >> a >> b;

    graphs[a].push_back(b);
    graphs[b].push_back(a);
  }

  bfs(-1, 1);
  for(int i=2;i<=N;i++) {
    cout << parents[i] << "\n";
  }
}