#include <cmath>
#include <iostream>
using namespace std;

int div_sum(int n);
bool is_amicable(int a, int b);
int find_chain(int n, int& smallest);

#define MAX 1000000

int sum_d[MAX + 1];
int chain[500];  // Arbitrary limit

int main()
{
  int smallest, this_len, longest_chain = 0, final;
  int i;

  for (i = 1; i <= MAX; i++)
    sum_d[i] = div_sum(i);

  for (i = 1; i <= MAX; i++)
  {
    this_len = find_chain(i, smallest);
    if (this_len > longest_chain)
    {
      longest_chain = this_len;
      final = smallest;
    }
  }

  cout << final << endl;

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

int find_chain(int n, int& smallest)
{
  int current, count = 0, min = n;
  int chain_len = 0;
  current = sum_d[n];

  while (current <= MAX)
  {
    if (current == n) break;
    for (int i = 0; i < chain_len; i++)
      if (current == chain[i]) return 0;
    chain[chain_len++] = current;
    count++;
    if (current < min) min = current;
    current = sum_d[current];
  }

  smallest = min;
  return current == n ? count : 0;
}
