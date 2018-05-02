#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int primes_count(int n, int p);  // Number of specified prime in n!
int power(int b, int e);
long long n_choose_m(int n, int m, bool& square_free);

// Primes under 50
int p[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

vector<long long> record;

int main()
{
  bool square_free;
  int n, m;
  long long num;
  long long result = 0;

  // Add 1 to the record so we don't have to waste time
  record.push_back(1);

  for (n = 2; n < 51; n++)
  {
    for (m = 1; m < n; m++)
    {
      square_free = true;
      num = n_choose_m(n, m, square_free);
      if (square_free) record.push_back(num);
    }
  }

  // Convert to set and back to vector to remove duplicates
  // Code snippet from https://stackoverflow.com/a/1041939
  set<long long> s(record.begin(), record.end());
  record.assign(s.begin(), s.end());

  for (long long n : record) result += n;

  cout << result << endl;

  return 0;
}

int primes_count(int n, int p)
{
  int cnt = 0;

  while (n != 0)
  {
    n /= p;
    cnt += n;
  }

  return cnt;
}

int power(int b, int e)
{
  int result = 1;

  for (int i = 0; i < e; i++)
  {
    result *= b;
  }

  return result;
}

long long n_choose_m(int n, int m, bool& square_free)
{
  int a, b, c;
  long long result = 1;
  int p_exp[15] = {};  // Exponents for each prime less than 50

  for (int i = 0; i < 15; i++)  // Looping through primes less than 50
  {
    a = primes_count(n, p[i]);
    b = primes_count(m, p[i]);
    c = primes_count(n - m, p[i]);
    p_exp[i] = a - b - c;

    if ((a - b - c) >= 2) square_free = false;
  }

  for (int i = 0; i < 15; i++)
  {
    result *= power(p[i], p_exp[i]);
  }

  return result;
}
