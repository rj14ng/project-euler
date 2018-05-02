#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  int lines = 15;
  int n[lines][lines] = {};  // initialise all values to 0

  ifstream f;
  f.open("p018_triangle.txt");
  int i, j;
  for (i = 0; i < lines; i++)
  {
    for (j = 0; j <= i; j++)
    {
      f >> n[i][j];
    }
  }
  f.close();

  // Using dynamic programming
  for (i = lines - 2; i >= 0; i--)
  {
    for (j = 0; j <= i; j++)
    {
      n[i][j] += n[i+1][j] > n[i+1][j+1] ? n[i+1][j] : n[i+1][j+1];
      // cout << i << " " << j << ": " << n[i][j] << endl;
    }
  }

  cout << n[0][0] << endl;

  return 0;
}
