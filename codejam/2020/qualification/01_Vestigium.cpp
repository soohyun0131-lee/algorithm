#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int arr[102][102];

int main()
{
  int TC;

  std::cin >> TC;

  for (int tc = 1; tc <= TC; tc++)
  {
    int N;
    int trace = 0;
    int repeatcol = 0;
    int repeatrow = 0;

    memset(arr, 0, sizeof(arr));

    std::cin >> N;
    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= N; j++)
      {
        std::cin >> arr[i][j];
        if (i == j)
          trace += arr[i][j];
      }
    }

    for (int i = 1; i <= N; i++)
    {
      vector<int> row(N + 1, 0);
      for (int j = 1; j <= N; j++)
      {
        if (row[arr[i][j]] == 1)
        {
          repeatrow++;
          break;
        }
        row[arr[i][j]]++;
      }
    }

    for (int i = 1; i <= N; i++)
    {
      vector<int> col(N + 1, 0);
      for (int j = 1; j <= N; j++)
      {
        if (col[arr[j][i]] == 1)
        {
          repeatcol++;
          break;
        }
        col[arr[j][i]]++;
      }
    }

    std::cout << "Case #" << tc << ": " << trace << " " << repeatrow << " " << repeatcol << std::endl;
  }
  return 0;
}
