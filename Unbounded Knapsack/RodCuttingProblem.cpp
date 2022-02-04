#include <bits/stdc++.h>
using namespace std;

int cutRod(int price[], int n) {
       int len[n];  //creating rod can can be cut into pieces 
       for(int i=0;i<n;i++)
       {
           len[i]=i+1;
       }
    int t[n+1][n+1];
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < n + 1; j++)
         if (i == 0 || j == 0)
                t[i][j] = 0;
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < n + 1; j++)
        {
            if (len[i - 1] <= j)
                t[i][j] = max(price[i - 1] + t[i][j - len[i - 1]], t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
    return t[n][n];
    }

int main()
{

    
    int price[] = {10,20,30,40,50,60};
    int n =6;
    cout << cutRod(price, n);
    return 0;
}
