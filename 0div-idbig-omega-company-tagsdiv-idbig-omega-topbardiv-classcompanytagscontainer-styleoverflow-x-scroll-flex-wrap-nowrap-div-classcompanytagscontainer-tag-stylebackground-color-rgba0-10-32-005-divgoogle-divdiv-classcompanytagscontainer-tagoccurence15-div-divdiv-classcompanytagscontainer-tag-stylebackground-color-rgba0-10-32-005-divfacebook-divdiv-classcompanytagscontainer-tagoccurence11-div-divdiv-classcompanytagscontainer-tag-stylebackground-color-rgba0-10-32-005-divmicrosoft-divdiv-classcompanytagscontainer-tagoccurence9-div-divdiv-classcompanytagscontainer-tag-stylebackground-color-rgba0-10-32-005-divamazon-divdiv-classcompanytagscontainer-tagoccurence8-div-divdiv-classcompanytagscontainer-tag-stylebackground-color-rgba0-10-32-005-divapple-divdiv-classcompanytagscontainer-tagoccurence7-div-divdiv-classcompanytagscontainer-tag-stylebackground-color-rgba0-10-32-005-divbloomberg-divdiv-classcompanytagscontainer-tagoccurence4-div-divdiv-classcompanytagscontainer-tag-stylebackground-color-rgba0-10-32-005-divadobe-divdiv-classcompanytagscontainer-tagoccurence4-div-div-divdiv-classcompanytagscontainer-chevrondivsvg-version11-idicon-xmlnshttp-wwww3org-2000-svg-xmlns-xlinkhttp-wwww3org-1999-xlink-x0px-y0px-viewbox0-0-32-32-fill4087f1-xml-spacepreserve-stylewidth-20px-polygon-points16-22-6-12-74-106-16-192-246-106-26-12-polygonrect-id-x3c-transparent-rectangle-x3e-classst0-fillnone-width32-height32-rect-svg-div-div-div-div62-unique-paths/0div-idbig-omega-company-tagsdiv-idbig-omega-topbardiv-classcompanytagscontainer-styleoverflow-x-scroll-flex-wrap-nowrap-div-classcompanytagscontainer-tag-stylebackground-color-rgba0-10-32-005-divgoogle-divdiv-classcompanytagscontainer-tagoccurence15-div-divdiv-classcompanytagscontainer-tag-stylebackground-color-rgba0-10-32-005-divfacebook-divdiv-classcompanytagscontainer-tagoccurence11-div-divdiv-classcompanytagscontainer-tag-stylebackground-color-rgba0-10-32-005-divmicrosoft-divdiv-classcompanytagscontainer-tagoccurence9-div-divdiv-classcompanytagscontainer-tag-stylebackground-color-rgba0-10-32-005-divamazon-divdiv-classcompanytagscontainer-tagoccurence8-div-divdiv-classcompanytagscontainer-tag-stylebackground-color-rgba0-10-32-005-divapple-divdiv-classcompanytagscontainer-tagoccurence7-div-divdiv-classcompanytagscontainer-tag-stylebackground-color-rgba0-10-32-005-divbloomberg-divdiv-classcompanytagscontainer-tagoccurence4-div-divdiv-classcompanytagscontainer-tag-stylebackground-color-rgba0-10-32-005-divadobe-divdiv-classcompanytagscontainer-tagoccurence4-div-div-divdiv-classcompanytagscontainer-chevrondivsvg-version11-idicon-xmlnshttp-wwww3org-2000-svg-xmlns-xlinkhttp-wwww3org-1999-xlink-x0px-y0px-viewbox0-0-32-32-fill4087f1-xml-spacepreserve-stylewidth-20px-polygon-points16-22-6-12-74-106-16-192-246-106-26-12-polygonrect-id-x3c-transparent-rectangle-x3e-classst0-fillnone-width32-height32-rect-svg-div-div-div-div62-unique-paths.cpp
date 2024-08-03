class Solution {
    int uniquePaths(int i, int j, vector<vector<int>> &dp)
    {
        if((i == 0) && (j ==0))
        {
            return 1;
        }
        
        if((i < 0) || (j < 0))
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int left = uniquePaths(i, j-1, dp);
        int up = uniquePaths(i-1, j, dp);
        
        return (dp[i][j] = left + up);
    }
    
public:
    int uniquePaths(int m, int n) {
#if 0
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return uniquePaths(m-1, n-1, dp);
#endif

#if 0
        vector<vector<int>> dp(m, vector<int>(n, 0));

        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if((i == 0) && (j == 0))
                {
                    dp[0][0] = 1;
                    continue;
                }
                
                int left = 0;
                if(j-1 >= 0)
                    left = dp[i][j-1];
                
                int up = 0;
                if(i-1 >= 0)
                    up = dp[i-1][j];
                
                dp[i][j] = left + up;
            }
        }
        
        return dp[m-1][n-1];
#endif
        
        vector<int> curr(n, 0), prev(n, 0);

        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if((i == 0) && (j == 0))
                {
                    curr[0] = 1;
                    continue;
                }
                
                int left = 0;
                if(j-1 >= 0)
                    left = curr[j-1];
                
                int up = 0;
                if(i-1 >= 0)
                    up = prev[j];
                
                curr[j] = left + up;
            }
            prev = curr;
        }
        
        return prev[n-1];
        
    }
};