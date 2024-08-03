class Solution {
    int mod = 2 * 1e9;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
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
    }
};