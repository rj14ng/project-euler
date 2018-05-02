#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool is_palindrome(int n);
bool is_new(int n);

vector<int> record;

int main()
{
  int limit = 100000000;
  int root_limit = (int)sqrt(limit * 1.0);

  int i, j;
  int sum = 0;
  int cnt = 0;
  long long total = 0;

  for (i = 1; i < root_limit; i++)
  {
    sum = i * i;
    j = i;
    while (true)
    {
      j++;
      sum += j * j;
      if (sum > limit) break;
      if (is_palindrome(sum) && is_new(sum))
      {
        record.push_back(sum);
        total += sum;
        cnt++;
      }
    }
  }

  cout << total << endl;

  return 0;
}

bool is_palindrome(int n)
{
  int n_save = n;
  int digit;
  int reverse = 0;

  while (n > 0)
  {
    digit = n % 10;
    n /= 10;
    reverse = 10 * reverse + digit;
  }

  if (reverse == n_save) return true;
  return false;
}

bool is_new(int n)
{
  if (find(record.begin(), record.end(), n) != record.end()) return false;
  return true;
}
