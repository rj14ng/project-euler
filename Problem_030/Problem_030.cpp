#include <iostream>
using namespace std;

int power(int n, int p)
{
  int result = n;
  for (int i = 1; i < p; i++)
  {
    result *= n;
  }
  return result;
}

int digit_nth_powers(int n)
{
  int total_sum = 0;

  for (int num_const = 2; num_const <= power(9, n) * n; num_const++)
  {
    int num = num_const;
    int sum = 0;
    while (num != 0)
    {
      int digit = num % 10;
      int digit_to_nth_power = power(digit, n);
      sum += digit_to_nth_power;
      num /= 10;
    }
    if (sum == num_const)
    {
      total_sum += num_const;
    }
  }

  return total_sum;
}

int main()
{
  cout << digit_nth_powers(5) << endl;
  return 0;
}
