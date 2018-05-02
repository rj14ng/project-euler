#include <iostream>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b);

int main()
{
  long long size = 1500000;
  long long* T = new long long[size + 1]();

  long long m, n;
  long long count = 0;
  long long limit = (int)sqrt((double)size / 2);

  for (m = 2; m <= limit; m++)
  {
    for (n = 1; n < m; n++)
    {
      if ((gcd(m, n) == 1) && ((m + n) % 2 == 1))
      {
        long long a = m * m - n * n;
        long long b = 2 * m * n;
        long long c = m * m + n * n;
        long long sum = a + b + c;
        long long p = sum;
        while (p <= size)
        {
          T[p]++;
          p += sum;
        }
      }
    }
  }

  for (m = 1; m <= size; m++)
  {
    if (T[m] == 1) count++;
  }

  cout << count << endl;

  return 0;
}

long long gcd(long long a, long long b)
{
  long long t;
  while (b != 0)
  {
    t = b;
    b = a % b;
    a = t;
  }

  return a;
}
