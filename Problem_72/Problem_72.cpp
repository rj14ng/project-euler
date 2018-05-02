#include <cstdio>

// Solution uses Euler's totient function
// Essentially sum of phi(i) for i = 2 to 1,000,000

int main()
{
  int size = 1000000;

  int i, j;

  int *phi;
  phi = new int[size + 1];

  for (i = 0; i <= size; i++)
    phi[i] = i;

  long long count = 0;
  for (i = 2; i <= size; i++)
  {
    if (phi[i] == i)
    {
      for (j = i; j <= size; j += i)
        phi[j] = phi[j] / i * (i - 1);
    }
    count += phi[i];
  }

  printf("%lld\n", count);

  return 0;
}
