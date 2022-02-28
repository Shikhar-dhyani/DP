// what is subsequence ?
// x= a b c d g h
// y= a b e d f h r
// subs. = abdh
#include <bits/stdc++.h>
using namespace std;

void lcs(char *X, char *Y, int m, int n)
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
    int i=m,j=n;
    string s;
    while(i>0&&j>0)
    {
        if(X[i-1]==Y[j-1])
        {
            s.push_back(X[i-1]);
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            i--;
            else
            j--;
        }
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl;
}
int main()
{
    char X[] = "ZXABCDEZY";
    char Y[] = "YZABCDEZX";

    int m = strlen(X);
    int n = strlen(Y);

    cout << " LCS is " ;
    lcs(X, Y, m, n);

    return 0;
}