#include <bits/stdc++.h>
using namespace std;

int lcs(string X, string Y, int m, int n)
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
    int t;
    cin>>t;
    int i=1;
    while(t--)
   { 
    string original ;
    string rendered;
    cin>>original>>rendered;
    int m=original.size();      //aaaaaa
    int n=rendered.size();      //aaaaab
     int lcss=lcs(rendered, original,n,m);
     if(m-lcss) cout<<"Case #"<<i <<": IMPOSSIBLE"<<endl;
     else  cout<<"Case #"<<i<<": "<<n-lcss<<endl;
     i++;
    }
    return 0;
}