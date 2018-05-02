#include <iostream>
#include <cmath>
using namespace std;

bool is_square(int n);

int main()
{
  int l = 1;
  int w, h;
  int cnt = 0;
  int target = 1000000;

  while (cnt < target)
  {
    l++;
    for (w = 1; w <= l; w++)
    {
      for (h = 1; h <= w; h++)
      {
        if (is_square(l * l + (w + h) * (w + h))) cnt++;
      }
    }
  }

  cout << l << endl;

  return 0;
}

bool is_square(int n)
{
  double root = sqrt((double)n);
  if (root == (int)root) return true;
  return false;
}
