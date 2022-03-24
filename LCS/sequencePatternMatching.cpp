// what is subsequence ?
// x= a b c d g h
// y= a b e d f h r
// subs. = abdh
#include <bits/stdc++.h>
using namespace std;

int lcs(char *X, char *Y, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    for (int i = 1; i < m + 1; i++)
        for (int j = 1; j < n + 1; j++)
        {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    return dp[m][n];
}
int main()
{
    char X[] = "AXY";
    char Y[] = "ABJJXKHHY";

    int m = strlen(X);
    int n = strlen(Y);

    if( lcs(X, Y, m, n)==m) cout<<"True";
    else cout<<"False";

    return 0;
}