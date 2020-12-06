#include <iostream>
#include <string>

using namespace std;

int changeToInt(char ch)
{
  return static_cast<int>(ch - '0');
}

int main()
{
  string newStr;
  string str;
  int remain = 0;
  int TC;

  std::cin >> TC;

  for (int tc = 1; tc <= TC; tc++)
  {
    remain = 0;
    newStr = "";
    std::cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
      int tmp = changeToInt(str[i]);
      if (tmp < remain)
      { // add )
        int num = remain - tmp;
        for (int j = 0; j < num; j++)
        {
          newStr += ")";
        }
      }
      else if (tmp > remain)
      { // add (
        int num = tmp - remain;
        for (int j = 0; j < num; j++)
        {
          newStr += "(";
        }
      }
      remain = tmp;
      newStr = newStr + str[i];
    }

    for (int j = 0; j < remain; j++)
    {
      newStr += ")";
    }

    std::cout << "Case #" << tc << ": " << newStr << std::endl;
  }
}