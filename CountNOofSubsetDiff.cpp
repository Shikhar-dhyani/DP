
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e18
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define pb push_back
// right top left bottom
ll dx[4] = {0, -1, 0, 1};
ll dy[4] = {1, 0, -1, 0};
int diff;
int subset(int a[], int n, int sum, int tempSum)
{

    int tab[n+1][sum+1] ;
    

    if (n < 0)
        return 0;

    int t = (sum - 2 * tempSum);
    if (t == diff)
        return 1;
    if (t < 0)
        return 0;

    return subset(a, n - 1, sum, tempSum + a[n - 1]) + subset(a, n - 1, sum, tempSum);
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], sum += a[i];
    cin >> diff;
    int tempSum = 0;
    cout << subset(a, n, sum, tempSum) << endl;
}

int main()
{
    FIO;
    ll test = 1;
    // cin >> test;

    while (test--)
    {
        solve();
    }
}
