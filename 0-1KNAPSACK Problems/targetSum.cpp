  #include <bits/stdc++.h>
using namespace std;

  int findTargetSumWays(vector<int>& nums, int S)
    {
        int n = nums.size();
        long int sum = accumulate(nums.begin(), nums.end(), 0);
        long int s1 = (sum+S)/2;
        if(S > sum || (sum+S)%2 != 0)
            return 0;
        
        int dp[n+1][s1+1];
        int zcount = 0;
        dp[0][0] = 1;
        for(int i = 1; i < n+1; i++)
        {
            if(nums[i-1] == 0)
                zcount++;
            dp[i][0] = pow(2, zcount);
        }
        for(int i = 1; i < s1+1; i++)
            dp[0][i] = 0;

        for(int i = 1; i < n+1; i++)
            for(int j = 1; j < s1+1; j++)
            {
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        return dp[n][s1];
    }
    int main()
{

    vector<int>v = {6, 2, 3, 1, 12};
    int n = v.size();
    cout <<findTargetSumWays(v,12);
    return 0;
}