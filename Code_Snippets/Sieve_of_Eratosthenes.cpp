#include <iostream>
#include <vector>
using namespace std;

int main()
{
  // Count up to how much
  int n = 100;

  int i, j;
  bool primes_bool[n + 1];
  vector<int> primes;

  // Initialise everything to true
  for (i = 0; i <= n; i++)
  {
    primes_bool[i] = true;
  }

  // 0 and 1 are not prime
  primes_bool[0] = false;
  primes_bool[1] = false;

  for (i = 2; i * i < n; i++)
  {
    if (primes_bool[i] == true)
    {
      for (j = i * 2; j <= n; j += i)
      {
        primes_bool[j] = false;
      }
    }
  }

  for (i = 0; i <= n; i++)
  {
    if (primes_bool[i] == true)
    {
      primes.push_back(i);
    }
  }

  // Print out
  for (int i : primes)
  {
    cout << i << endl;
  }

  return 0;
}
