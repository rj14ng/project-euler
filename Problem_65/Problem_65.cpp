// SINCE THE STORED NUMBERS ARE LARGE THEY ARE SPLIT INTO ARRAYS

#include <iostream>
using namespace std;

int main()
{
  int size = 100;
  int a[100];
  int d[20] = {};  // denominator
  int n[20] = {};  // numerator
  int i, j, k, tmp;

  a[0] = 2;
  for (i = 1; i < size; i++)
  {
    a[i] = 1;
    if (i % 3 == 2)
    {
      a[i] = 2 * (i + 1) / 3;
    }
  }

  n[0] = 1;
  k = size - 1;
  d[0] = a[k];

  while (k > 0)
  {
    k--;
    for (j = 0; j < 20; j++)
    {
      tmp = n[j];
      n[j] = d[j];
      d[j] = a[k] * d[j] + tmp;
    }
    for (j = 0; j < 20 - 1; j++)
    {
      d[j + 1] += d[j] / 10000;
      d[j] = d[j] % 10000;
    }
  }

  int ans = 0;
  for (i = 0; i < 20; i++)
  {
    while (d[i] != 0)
    {
      ans += d[i] % 10;
      d[i] /= 10;
    }
  }

  cout << ans << endl;

  return 0;
}
