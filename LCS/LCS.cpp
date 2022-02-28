// what is subsequence ?
// x= a b c d g h 
// y= a b e d f h r
// subs. = abdh
#include<bits/stdc++.h>
using namespace std;

int t[1001][1001];

int lcs( char *X, char *Y, int m, int n )
{
    if (m == 0 || n == 0)
        return 0;
        if(t[m][n]!=-1) return t[m][n];
    if (X[m-1] == Y[n-1])
        return t[m][n]=1 + lcs(X, Y, m-1, n-1);
    else
        return t[m][n]= max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}
int main()
{
    memset(t,-1,sizeof(t));
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
     
    int m = strlen(X);
    int n = strlen(Y);
     
    cout<<"Length of LCS is "<< lcs( X, Y, m, n ) ;
     
    return 0;
}