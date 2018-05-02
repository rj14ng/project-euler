#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
  int exp[1000][2];
  int i;
  char c;  // throw away the commas

  ifstream f;
  f.open("p099_base_exp.txt");
  for (i = 0; i < 1000; i++)
  {
    f >> exp[i][0] >> c >> exp[i][1];
  }

  double max_num = 0;
  int max_line = 0;
  double n;

  for (i = 0; i < 1000; i++)
  {
    n = exp[i][1] * log10(exp[i][0] * 1.0);
    if (n > max_num)
    {
      max_line = i + 1;
      max_num = n;
    }
  }

  cout << max_line << endl;

  return 0;
}
