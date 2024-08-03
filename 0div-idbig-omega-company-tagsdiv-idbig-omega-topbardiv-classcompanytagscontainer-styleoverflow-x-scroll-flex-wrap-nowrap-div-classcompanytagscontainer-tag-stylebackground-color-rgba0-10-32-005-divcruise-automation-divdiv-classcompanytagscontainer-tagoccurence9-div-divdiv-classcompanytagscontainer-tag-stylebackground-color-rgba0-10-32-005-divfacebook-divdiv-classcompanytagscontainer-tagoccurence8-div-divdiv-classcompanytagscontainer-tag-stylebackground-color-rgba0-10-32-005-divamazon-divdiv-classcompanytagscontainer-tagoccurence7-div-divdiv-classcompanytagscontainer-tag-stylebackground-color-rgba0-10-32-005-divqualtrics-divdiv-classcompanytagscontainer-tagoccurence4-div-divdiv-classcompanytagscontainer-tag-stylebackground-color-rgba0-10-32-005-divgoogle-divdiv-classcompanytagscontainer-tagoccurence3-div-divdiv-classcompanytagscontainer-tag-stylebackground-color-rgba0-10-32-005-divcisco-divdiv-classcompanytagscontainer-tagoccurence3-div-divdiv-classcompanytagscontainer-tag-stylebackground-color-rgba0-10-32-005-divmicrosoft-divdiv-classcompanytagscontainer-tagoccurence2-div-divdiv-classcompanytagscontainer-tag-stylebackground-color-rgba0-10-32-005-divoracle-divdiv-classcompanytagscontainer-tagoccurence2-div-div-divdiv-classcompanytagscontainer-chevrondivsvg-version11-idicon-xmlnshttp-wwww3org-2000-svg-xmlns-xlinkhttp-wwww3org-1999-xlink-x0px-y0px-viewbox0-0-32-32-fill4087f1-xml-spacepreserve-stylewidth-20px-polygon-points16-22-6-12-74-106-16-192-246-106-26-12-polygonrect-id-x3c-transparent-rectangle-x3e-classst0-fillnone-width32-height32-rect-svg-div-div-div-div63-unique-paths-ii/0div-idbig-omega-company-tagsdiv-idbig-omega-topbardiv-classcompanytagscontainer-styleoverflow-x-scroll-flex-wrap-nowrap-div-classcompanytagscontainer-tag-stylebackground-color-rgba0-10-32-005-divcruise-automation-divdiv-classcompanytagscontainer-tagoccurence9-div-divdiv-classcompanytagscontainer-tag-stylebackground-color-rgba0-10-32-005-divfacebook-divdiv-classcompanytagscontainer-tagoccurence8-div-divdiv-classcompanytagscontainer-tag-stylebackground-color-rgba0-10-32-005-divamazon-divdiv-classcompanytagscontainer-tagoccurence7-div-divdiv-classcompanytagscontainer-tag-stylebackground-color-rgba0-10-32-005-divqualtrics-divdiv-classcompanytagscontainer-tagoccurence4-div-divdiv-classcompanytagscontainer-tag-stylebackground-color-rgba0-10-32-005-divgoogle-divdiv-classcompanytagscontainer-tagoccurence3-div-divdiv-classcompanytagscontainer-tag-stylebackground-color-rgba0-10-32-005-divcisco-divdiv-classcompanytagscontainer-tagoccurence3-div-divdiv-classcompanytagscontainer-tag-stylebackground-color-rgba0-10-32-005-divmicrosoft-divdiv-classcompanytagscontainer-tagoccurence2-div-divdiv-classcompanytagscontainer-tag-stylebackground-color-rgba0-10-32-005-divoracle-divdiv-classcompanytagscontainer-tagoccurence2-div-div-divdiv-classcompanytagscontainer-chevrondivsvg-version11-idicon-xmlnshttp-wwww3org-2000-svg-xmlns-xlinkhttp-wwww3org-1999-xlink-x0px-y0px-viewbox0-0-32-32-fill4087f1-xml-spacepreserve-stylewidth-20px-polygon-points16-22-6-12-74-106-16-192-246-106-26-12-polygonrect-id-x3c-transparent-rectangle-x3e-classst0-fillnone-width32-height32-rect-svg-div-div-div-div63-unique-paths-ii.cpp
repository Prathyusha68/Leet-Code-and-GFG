class Solution {
    int mod = 2 * 1e9;
    
    int uniquePathsWithObstacles(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp)
    {
        if((i == 0) && (j ==0))
        {
            return 1;
        }
        
        if((i < 0) || (j < 0))
            return 0;
        
        if(grid[i][j] == 1)
        {
            return dp[i][j] = 0;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int left = uniquePathsWithObstacles(i, j-1, grid, dp);
        int up = uniquePathsWithObstacles(i-1, j, grid, dp);
        
        return (dp[i][j] = left + up);
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        if(obstacleGrid[0][0] == 1)
            return 0;
        
        return uniquePathsWithObstacles(m-1, n-1, obstacleGrid, dp);
#if 0
        if(obstacleGrid[0][0] == 1)
            return 0;
        
        vector<int> curr(n, 0), prev(n, 0);

        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    curr[j] = 0;
                    continue;
                }
                
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
                
                curr[j] = (left + up) % mod;
            }
            prev = curr;
        }
        
        return prev[n-1];
#endif
    }
};