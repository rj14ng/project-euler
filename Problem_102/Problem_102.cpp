#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

/*
 Algorithm based on:
 Area of ABP + APC + PBC = Area of ABC if P is in ABC
 */

int find_area(int x1, int y1, int x2, int y2, int x3, int y3);
int find_area_origin(int x1, int y1, int x2, int y2);

int main()
{
  ifstream f;
  int x1, y1, x2, y2, x3, y3;
  int a, a1, a2, a3;
  int t = 1000;
  int cnt = 0;
  char c;  // throw away the commas

  f.open("p102_triangles.txt");

  for (int i = 0; i < t; i++)
  {
    f >> x1 >> c >> y1 >> c >> x2 >> c >> y2 >> c >> x3 >> c >> y3;

    a = find_area(x1, y1, x2, y2, x3, y3);
    a1 = find_area_origin(x1, y1, x2, y2);
    a2 = find_area_origin(x2, y2, x3, y3);
    a3 = find_area_origin(x1, y1, x3, y3);

    if (a == (a1 + a2 + a3)) cnt++;
  }

  cout << cnt << endl;

  return 0;
}

int find_area(int x1, int y1, int x2, int y2, int x3, int y3)
{
  // Finds area of a triangle based on the determinant of vertices
  // Computed from elements of square matrix
  // Function finds double the area since formula requires halving
  // However it is not necessary to halve
  return abs(x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3);
}

int find_area_origin(int x1, int y1, int x2, int y2)
{
  // Based on find_area function but one set of coordinates is (0, 0)
  return abs(x1 * y2 - x2 * y1);
}
