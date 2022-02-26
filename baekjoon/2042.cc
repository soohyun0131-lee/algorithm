#include <algorithm>
#include <iostream>

using namespace std;

int arr[2000010];
int input[1000001];
int N, M, K;

int main() {
  std::cin >> N >> M >> K;

  for(int i=1;i<=N;i++) {
    std::cin >> input[i];
  }

  
}

int calculateSegTree(int i) {
  if(i*2 <= N) {
    arr[i] = arr[i*2] + arr[i*2+1];
    return arr[i];
  }
  
  arr[i] = calculateSegTree(i*2) + calculateSegTree(i*2+1);
  return arr[i];
}