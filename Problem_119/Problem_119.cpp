#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long digit_sum(long long n);

int main()
{
  // Set an arbitrary limit (highest value of of long long)
  long long limit = 9223372036854775807;
  long long b, p;
  int cnt = 0;
  vector<long long> a;

  for (b = 2; b < 100; b++)
  {
    p = b;
    while (p < limit / b)
    {
      p *= b;
      if (b == digit_sum(p))
      {
        a.push_back(p);
        cnt++;
        // Get extra terms just in case, since what we get is unordered
        if (cnt > 100) break;
      }
    }
  }

  // Sort the vector and output a30
  sort(a.begin(), a.end());
  cout << a[29] << endl;
  return 0;

}

long long digit_sum(long long n)
{
  int sum = 0;
  while (n != 0)
  {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
