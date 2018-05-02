#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int no_factors(int n);
int no_factors_n2(int n);

int main()
{
  int limit = 1000;
  int result;

  for (int i = 4; i < 1000000; i++) // Arbitary limit
  {
    if (((no_factors_n2(i) + 1) / 2) > limit)
    {
      result = i;
      break;
    }
  }

  cout << result << endl;

  return 0;
}

// Find factors of n
int no_factors_n(int n)
{
  if (n == 1) return 1;
  int cnt = 0;
  int root = (int)sqrt((double)n);
  for (int i = 2; i <= root; i++)
  {
    if (n % i == 0)
    {
      while (n % i == 0)
      {
        cnt++;
        n /= i;
      }
      return (cnt + 1) * no_factors_n(n);
    }
  }
  return 2;
}

// Find factors of n^2
int no_factors_n2(int n)
{
  if (n == 1) return 1;
  int cnt = 0;
  int root = (int)sqrt((double)n);
  for (int i = 2; i <= root; i++)
  {
    if (n % i == 0)
    {
      while (n % i == 0)
      {
        cnt++;
        n /= i;
      }
      return (2 * cnt + 1) * no_factors_n2(n);
    }
  }
  return 3;
}
