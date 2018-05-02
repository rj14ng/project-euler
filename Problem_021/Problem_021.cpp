#include <cmath>
#include <iostream>
using namespace std;

int div_sum(int n);
bool is_amicable(int a, int b);

int main()
{
  int max = 10000;

  int i, j;
  int sum = 0;

  for (i = 1; i < max; i++)
  {
    j = div_sum(i);
    if (is_amicable(i, j)) sum += i;
  }

  cout << sum << endl;

  return 0;
}

int div_sum(int n)
{
  int sum = 1;  // 1 is also a divisor so we add it first

  for (int i = 2; i <= sqrt(n); i++)
  {
    if (n % i == 0)
    {
      if (i == n / i)  // If both divisors are the same, add only once
        sum += i;
      else  // Else add both
        sum += (i + n / i);
    }
  }

  return sum;
}

bool is_amicable(int a, int b)
{
  if (a == b) return false;
  if ((div_sum(a) == b) && (div_sum(b) == a)) return true;
  return false;
}
