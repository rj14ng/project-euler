#include <iostream>
#include <cmath>
using namespace std;

/*
 Algorithm based on binomial series
 We only need to consider last 2 terms of the series
 Since the other terms are divisible by a^2

 (a - 1)^n = ... + (n choose n-1) * (-1)^(n-1) * a + (-1)^n
 (a + 1)^n = ... + (n choose n-1) * a + 1

 If n is even the second last terms cancel out so r = 2  -> not max
 If n is odd r = 2 * (n choose n-1) * a = 2 * n * a

 The largest multiple under a^2 is a(a-1)
 So see if that is achievable with 2na
 n = floor( (a-1)/2 )

 */

int main()
{
  int sum = 0;

  for (int a = 3; a <= 1000; a++)
  {
    sum += 2 * ((a - 1) / 2) * a;
  }

  cout << sum << endl;

  return 0;
}
