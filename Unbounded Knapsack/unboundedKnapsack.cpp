#include <bits/stdc++.h>
using namespace std;
int t[102][1002];
int unknapSack (int wt[], int val[], int w, int n)
{
  if (n == 0 || w == 0)
    return 0;
  if (t[n][w] != -1)
    return t[n][w];
  if (wt[n - 1] <= w)
    return t[n][w] = max (val[n - 1] + unknapSack (wt, val, w - wt[n - 1], n),
    unknapSack (wt, val, w, n - 1));

  else
    return t[n][w] = unknapSack (wt, val, w, n - 1);
}

int main ()
{
  memset (t, -1, sizeof (t));
  int val[] = { 60, 100, 120 };
  int wt[] = { 10, 20, 30 };
  int W = 50;
  int n = sizeof (val) / sizeof (val[0]);
  cout << unknapSack (wt, val, W, n);
  return 0;
}
