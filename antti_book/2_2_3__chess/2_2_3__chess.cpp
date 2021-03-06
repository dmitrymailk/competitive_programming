#include <iostream>

using namespace std;

int n = 4;
int count = 0;
void search(int y)
{
  if (y == n)
  {
    count++;
    return;
  }
  for (int x = 0; x < n; x++)
  {
    if (col[x] || diag1[x + y] || diag2[x - y + n - 1])
      continue;
    col[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
    search(y + 1);
    col[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
  }
}

int main()
{
  search(0);
}