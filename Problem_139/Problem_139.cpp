#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b);

int main()
{
  int limit = 100000000;
  int m_limit = (int)sqrt(limit / 2);
  int a, b, c, p;
  int cnt = 0;

  for (int m = 2; m < m_limit; m++)
  {
    for (int n = 1; n < m; n++)
    {
      // Conditions for Euclid's formula: not both odd and relatively prime
      if (((m + n) % 2 == 1) && (gcd(m, n) == 1))
      {
        a = 2 * m * n;
        b = m * m - n * n;
        c = m * m + n * n;
        p = a + b + c;
        if (c % (b - a) == 0)  // If it can be tiled
        {
          cnt += limit / p;
        }
      }
    }
  }

  cout << cnt << endl;

  return 0;
}

int gcd(int a, int b)
{
  int t;
  while (b != 0)
  {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}
