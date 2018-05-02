#include <iostream>
using namespace std;

int main()
{
  int n = 100;
  int ways[n + 1] = {};
  ways[0] = 1;

  for (int i = 1; i <= n - 1; i++)
  {
    for (int j = i; j <= n; j++)
    {
      ways[j] += ways[j - i];
    }
  }

  cout << ways[n] << endl;

  return 0;
}
