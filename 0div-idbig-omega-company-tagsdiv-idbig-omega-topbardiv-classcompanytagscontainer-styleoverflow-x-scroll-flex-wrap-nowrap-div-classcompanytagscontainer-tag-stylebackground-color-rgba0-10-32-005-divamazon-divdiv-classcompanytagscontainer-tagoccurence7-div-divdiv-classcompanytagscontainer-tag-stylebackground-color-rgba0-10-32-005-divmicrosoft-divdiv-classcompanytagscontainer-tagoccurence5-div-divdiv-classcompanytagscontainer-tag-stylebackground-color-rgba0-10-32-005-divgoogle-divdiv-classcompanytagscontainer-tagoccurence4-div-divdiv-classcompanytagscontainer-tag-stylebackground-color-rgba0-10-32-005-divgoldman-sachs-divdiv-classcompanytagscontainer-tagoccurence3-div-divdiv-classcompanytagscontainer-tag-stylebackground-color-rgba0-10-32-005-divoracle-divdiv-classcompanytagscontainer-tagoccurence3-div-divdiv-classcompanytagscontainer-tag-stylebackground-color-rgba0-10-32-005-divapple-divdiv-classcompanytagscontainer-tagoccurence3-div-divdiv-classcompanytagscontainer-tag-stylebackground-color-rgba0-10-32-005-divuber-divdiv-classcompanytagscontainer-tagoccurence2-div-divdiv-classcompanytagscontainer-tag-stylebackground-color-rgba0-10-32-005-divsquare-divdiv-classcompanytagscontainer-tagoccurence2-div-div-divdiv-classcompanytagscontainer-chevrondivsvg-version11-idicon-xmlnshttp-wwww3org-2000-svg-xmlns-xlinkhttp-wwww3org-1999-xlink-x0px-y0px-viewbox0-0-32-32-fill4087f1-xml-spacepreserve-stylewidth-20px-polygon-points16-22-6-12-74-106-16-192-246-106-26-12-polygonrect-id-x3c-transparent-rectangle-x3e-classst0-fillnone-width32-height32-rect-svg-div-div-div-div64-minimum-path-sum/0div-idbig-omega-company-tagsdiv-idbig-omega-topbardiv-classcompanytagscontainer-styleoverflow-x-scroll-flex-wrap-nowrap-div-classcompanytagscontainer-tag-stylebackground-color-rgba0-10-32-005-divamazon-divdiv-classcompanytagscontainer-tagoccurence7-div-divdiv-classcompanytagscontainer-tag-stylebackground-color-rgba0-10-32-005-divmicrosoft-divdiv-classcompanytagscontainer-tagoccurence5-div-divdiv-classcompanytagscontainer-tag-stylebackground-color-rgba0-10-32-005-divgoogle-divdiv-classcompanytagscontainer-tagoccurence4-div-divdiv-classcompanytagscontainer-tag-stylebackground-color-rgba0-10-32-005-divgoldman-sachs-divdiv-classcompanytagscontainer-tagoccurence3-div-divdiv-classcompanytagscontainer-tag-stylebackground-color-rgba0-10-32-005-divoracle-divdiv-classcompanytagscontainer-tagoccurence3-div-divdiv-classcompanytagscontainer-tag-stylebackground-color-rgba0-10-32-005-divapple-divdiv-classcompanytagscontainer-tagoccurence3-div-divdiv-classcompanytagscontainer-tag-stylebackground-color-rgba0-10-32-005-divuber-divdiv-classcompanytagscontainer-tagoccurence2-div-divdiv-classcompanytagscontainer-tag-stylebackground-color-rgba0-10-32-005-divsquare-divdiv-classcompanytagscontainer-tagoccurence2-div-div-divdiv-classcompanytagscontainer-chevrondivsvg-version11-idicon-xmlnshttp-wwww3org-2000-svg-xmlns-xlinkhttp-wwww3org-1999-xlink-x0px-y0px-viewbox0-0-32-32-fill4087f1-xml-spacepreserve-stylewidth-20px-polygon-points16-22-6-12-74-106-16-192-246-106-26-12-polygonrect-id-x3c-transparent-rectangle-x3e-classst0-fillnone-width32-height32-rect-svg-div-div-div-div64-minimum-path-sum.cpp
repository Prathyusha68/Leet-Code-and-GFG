class Solution {
    int minPathSum(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp)
    {
        if((i == 0) && (j ==0))
        {
            return grid[0][0];
        }
        
        if((i < 0) || (j < 0))
            return 1e8;
        
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int left = grid[i][j] + minPathSum(i, j-1, grid, dp);
        int up = grid[i][j] + minPathSum(i-1, j, grid, dp);
        
        return (dp[i][j] = min(left, up));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return minPathSum(m-1, n-1, grid, dp);
    }
};