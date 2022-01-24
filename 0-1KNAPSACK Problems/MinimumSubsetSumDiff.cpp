#include <bits/stdc++.h>
using namespace std;

int subsetsum(int arr[], int sum, int n)
{
    int t[n+1][sum+1];
    int mn=INT_MAX;
    vector<int>v;
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                t[i][j] =0;
            if (j == 0)
                t[i][j] = 1;
        }
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j -arr[i - 1]]||t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }
         for(int i=0;i<=sum/2;i++)
        if(t[n][i]) v.push_back(i);

        for(int i=0;i<v.size();i++)
        mn=min(mn,sum-2*(v[i]));
    return mn;
}

int main()
{

    int arr[] = {6, 2, 30, 18, 11};
    int n = sizeof(arr) / sizeof(arr[0]),sum=0;
    for(int i=0;i<n;i++)
    sum+=arr[i];
    cout<<subsetsum(arr,sum,n);
    return 0;
}