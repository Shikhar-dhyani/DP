#include <bits/stdc++.h>
using namespace std;

bool subsetsum(int arr[], int sum, int n)
{
    int t[n+1][sum+1];
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                t[i][j] = 0;
            if (j == 0)
                t[i][j] = 1;
        }
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j -arr[i - 1]]||t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }
    return t[n][sum];
}

int main()
{

    int arr[] = {6, 2, 3, 1, 120};
    int sum = 5;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << subsetsum(arr, sum, n);
    return 0;
}