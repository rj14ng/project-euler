#include <iostream>
using namespace std;

bool is_permutation(int m, int n);

int main()
{
  int size = 10000000;
  int i, j;

  int *phi;
  phi = new int[size + 1];

  for (i = 0; i <= size; i++)
    phi[i] = i;
  for (i = 2; i <= size; i++)
  {
    if (phi[i] == i)
    {
      for (j = i; j <= size; j += i)
      {
        phi[j] = phi[j] / i * (i - 1);
      }
    }
  }

  double min_ratio = 1000000;
  int index = 1;
  for (i = 2; i <= size; i++)
  {
    if (is_permutation(i, phi[i]))
    {
      double ratio = (double) i / phi[i];
      if (min_ratio > ratio)
      {
        min_ratio = ratio;
        index = i;
      }
    }
  }

  cout << index << endl;

  return 0;
}

bool is_permutation(int m, int n)
{
  int n_digits_m, n_digits_n;
  int dm[10], dn[10];
  int count = 0;
  while (n > 0)
  {
    dn[count] = n % 10;
    n /= 10;
    count++;
  }
  n_digits_n = count;
  count = 0;
  while (m > 0)
  {
    dm[count] = m % 10;
    m /= 10;
    count++;
  }
  n_digits_m = count;
  if (n_digits_n != n_digits_m) return false;

  int c, d;
  // Bubble sort
  for (c = 0; c < n_digits_n - 1; c++)
  {
    for (d = 0; d < n_digits_n - c - 1; d++)
    {
      if (dn[d] > dn[d + 1])
      {
        int swap = dn[d];
        dn[d] = dn[d + 1];
        dn[d + 1] = swap;
      }
    }
  }
  for (c = 0; c < n_digits_m - 1; c++)
  {
    for (d = 0; d < n_digits_m - c - 1; d++)
    {
      if (dm[d] > dm[d + 1])
      {
        int swap = dm[d];
        dm[d] = dm[d + 1];
        dm[d + 1] = swap;
      }
    }
  }

  int i;
  bool b_equal = true;
  for (i = 0; i < n_digits_n; i++)
  {
    if (dm[i] != dn[i])
    {
      b_equal = false;
      break;
    }
  }

  return b_equal;
}
