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
public:
    int climbStairs(int n) {
        vector<int> dp(n, -1);
        return climbRecursive(n, 0, dp);
    }
};