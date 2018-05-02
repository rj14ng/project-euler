#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int div_sum(int n);
bool is_abundant(int n);

int main()
{
  int limit = 28123;
  int i, j;
  int sum = 0;

  vector<int> abundant;
  for (i = 1; i <= limit; i++)
    if (is_abundant(i)) abundant.push_back(i);

  bool can_be_sum_of_abundant[limit + 1];
  for (i = 0; i < abundant.size(); i++)
  {
    for (j = i; j < abundant.size(); j++)
    {
      if (abundant[i] + abundant[j] <= limit)
        can_be_sum_of_abundant[abundant[i] + abundant[j]] = true;
      else
        break;
    }
  }

  for (i = 1; i <= limit; i++)
  {
    if (!can_be_sum_of_abundant[i]) sum += i;
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

bool is_abundant(int n)
{
  if (div_sum(n) > n) return true;
  return false;
}
