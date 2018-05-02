// BRUTE FORCE SOLUTION

#include <iostream>
using namespace std;

bool is_bouncy(int n);

int main()
{
  int cnt = 0;
  int i = 99;  // no bouncy numbers under 100

  while (cnt < 0.99 * i)
  {
    i++;
    if (is_bouncy(i)) cnt++;
  }

  cout << i << endl;

  return 0;
}

bool is_bouncy(int n)
{
  bool is_up = false;
  bool is_down = false;
  int left_digit;
  int right_digit = n % 10;
  n /= 10;

  while (n > 0)
  {
    left_digit = n % 10;
    if (left_digit < right_digit) is_up = true;
    else if (left_digit > right_digit) is_down = true;

    if (is_up && is_down) return true;
    n /= 10;
    right_digit = left_digit;
  }

  return false;
}
