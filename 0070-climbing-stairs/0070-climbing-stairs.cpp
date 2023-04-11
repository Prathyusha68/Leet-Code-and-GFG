class Solution {
    int climbRecursive(int n, int i, vector<int> &dp)
    {
        if(i >= n)
        {
            if(i == n)
                return 1;
            else
                return 0;
        }
        
        if(dp[i] != -1)
            return dp[i];
        
        return (dp[i] = (climbRecursive(n, i+1, dp) + climbRecursive(n, i+2, dp)));
    }
    
    int climbTabulation(int n)
    {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    
    int optimization(int n)
    {
        int prev1 = 1;
        int prev2 = 1;
        int curr = 1;
        for(int i = 2; i <= n; i++)
        {
            int tmp = curr;
            curr = prev1+prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n, -1);
        //return climbRecursive(n, 0, dp);
        return optimization(n);
    }
};