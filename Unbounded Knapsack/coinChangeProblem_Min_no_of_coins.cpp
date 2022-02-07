// Best thing of this question is you have to initialise DP table with INT_MAX-1
// instead of INT_MAX. Reason: if we take INT_MAX as intialisation, 
// then in dp[i][j] = min((dp[i][j-a[i-1]]+1), dp[i-1][j]),    
// (dp[i][j-a[i-1]]+1) ==> this part become INT_MIN if case is not valid and 
// min(INT_MIN, INT_MAX) = INT_MIN which affects our answer.
//INT_MAX +1 = INT_MIN
#include <bits/stdc++.h>
using namespace std;

int coinchange(int coins[], int sum, int n)
{
    int t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
                t[i][j] = 0;
            if (i == 0)
                t[i][j] = INT_MAX-1;
            if(i==1&&j!=0){
                if(j%coins[0]==0)
                t[i][j]=j/coins[0];
                else 
                t[i][j]=INT_MAX-1;
            }
        }
    for (int i = 2; i < n + 1; i++)
        for (int j = 1; j < sum + 1; j++)
        {
            if (coins[i - 1] <= j)
                t[i][j] = min(1 + t[i][j - coins[i - 1]], t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
    return t[n][sum];
}
int main()
{
    int coins[] = {25, 5, 10};
    int sum = 30;
    int n = sizeof(coins) / sizeof(coins[0]);
    cout << coinchange(coins, sum, n);
    return 0;
}