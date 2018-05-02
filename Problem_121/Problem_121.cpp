// Uses scenario trees

#include <iostream>
using namespace std;

int main()
{
  int turns = 15;
  int i;
  long long outcomes[16], save[16];

  outcomes[0] = 1;
  outcomes[1] = 1;
  int cnt = 1;

  while (cnt < turns)
  {
    cnt++;

    for (i = 0; i < cnt; i++)
    {
      save[i] = outcomes[i];
    }

    outcomes[cnt] = save[cnt - 1] * cnt;

    for (i = 1; i < cnt; i++)
    {
      outcomes[i] = save[i - 1] * cnt + save[i];
    }
  }

  long long sum_total = 0;
  for (i = 0; i <= turns; i++)
  {
    sum_total += outcomes[i];
  }

  long long sum_more_blue = 0;
  for (i = 0; i < turns / 2 + 1; i++)
  {
    sum_more_blue += outcomes[i];
  }

  cout << sum_total / sum_more_blue << endl;

  return 0;
}
