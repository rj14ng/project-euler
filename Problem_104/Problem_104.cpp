#include <cmath>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

bool is_1_to_9_pandigital(int n);
bool is_1_to_9_pandigital_last(int n);
long double fib_n(int n);  // Calculates nth term of Fibonnaci sequence (unused)
int digits_count(long double n);
int get_first_9_digits(long double n);

int main()
{

  int count = 1;
  int index;
  int result;
  long double fd;
  int first_9_digits;

  long double r5 = sqrt(5.0);
  long double phi1 = (1 + r5) / 2;
  long double term = phi1 / r5;

  while (true)
  {
    if (term > (long double) 1e20) term /= (long double) 1e20;  // Take care of overflow, we only care about first digits
    fd = term;
    term *= phi1;
    first_9_digits = get_first_9_digits(fd);
    // cout << count << " " << first_9_digits << endl;
    if (is_1_to_9_pandigital(first_9_digits))
    {
      index = count;
      if (is_1_to_9_pandigital_last(index))
      {
        result = index;
        break;
      }
    }
    count++;
  }

  cout << result << endl;

  return 0;
}

bool is_1_to_9_pandigital(int n)
{
  if ((n > 987654321) || (n < 123456789)) return false;

  vector<int> digits = {0};
  while (n != 0)
  {
    digits.push_back(n % 10);
    n /= 10;
  }

  // Convert to set and back to vector to remove duplicates
  // Code snippet from https://stackoverflow.com/a/1041939
  set<int> s(digits.begin(), digits.end());
  digits.assign(s.begin(), s.end());

  // Looking for if all digits are in the number
  // Since the vector is already initialised with 0 it needs 1-9 to make the length 10
  // Bad solution, don't care. Too tired.
  if (digits.size() != 10) return false;
  return true;
}

bool is_1_to_9_pandigital_last(int n)
{
  int count = 2;
  int f1 = 1;
  int f2 = 1;
  int f;

  while (count < n)
  {
    f = f1 + f2;
    f %= 1000000000;
    count++;
    f1 = f2;
    f2 = f;
  }

  return is_1_to_9_pandigital(f);
}

// UNUSED
long double fib_n(int n)
{
  double fn = n * 1.0;
  double r5 = sqrt(5.0);
  // return (1 / r5) * (pow((1 + r5) / 2, fn) - pow((1 - r5) / 2, fn));
  // When n becomes very large, pow((1 - r5) / 2, fn) becomes negligible
  return (1 / r5) * (pow((1 + r5) / 2, fn));
}

int digits_count(long double n)
{
  return (int) log10(n) + 1;
}

int get_first_9_digits(long double n)
{
  return (int) (n / pow(10.0L, (long double)digits_count(n) - 9));
}
