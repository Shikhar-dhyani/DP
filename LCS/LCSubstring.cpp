#include <bits/stdc++.h>
using namespace std;

int lcsubstring(char *X, char *Y, int m, int n)
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
                dp[i][j] = 0;
        }
    int maxi=0;
   for (int i = 0; i < m + 1; i++)
        for (int j = 0; j < n + 1; j++)
        if(maxi<dp[i][j]) maxi=dp[i][j];

    return maxi;
}
int main()
{
    char X[] = "WS";
    char Y[] = "WSSW";

    int m = strlen(X);
    int n = strlen(Y);

    cout << "Length of LCS is " << lcsubstring(X, Y, m, n);

    return 0;
}