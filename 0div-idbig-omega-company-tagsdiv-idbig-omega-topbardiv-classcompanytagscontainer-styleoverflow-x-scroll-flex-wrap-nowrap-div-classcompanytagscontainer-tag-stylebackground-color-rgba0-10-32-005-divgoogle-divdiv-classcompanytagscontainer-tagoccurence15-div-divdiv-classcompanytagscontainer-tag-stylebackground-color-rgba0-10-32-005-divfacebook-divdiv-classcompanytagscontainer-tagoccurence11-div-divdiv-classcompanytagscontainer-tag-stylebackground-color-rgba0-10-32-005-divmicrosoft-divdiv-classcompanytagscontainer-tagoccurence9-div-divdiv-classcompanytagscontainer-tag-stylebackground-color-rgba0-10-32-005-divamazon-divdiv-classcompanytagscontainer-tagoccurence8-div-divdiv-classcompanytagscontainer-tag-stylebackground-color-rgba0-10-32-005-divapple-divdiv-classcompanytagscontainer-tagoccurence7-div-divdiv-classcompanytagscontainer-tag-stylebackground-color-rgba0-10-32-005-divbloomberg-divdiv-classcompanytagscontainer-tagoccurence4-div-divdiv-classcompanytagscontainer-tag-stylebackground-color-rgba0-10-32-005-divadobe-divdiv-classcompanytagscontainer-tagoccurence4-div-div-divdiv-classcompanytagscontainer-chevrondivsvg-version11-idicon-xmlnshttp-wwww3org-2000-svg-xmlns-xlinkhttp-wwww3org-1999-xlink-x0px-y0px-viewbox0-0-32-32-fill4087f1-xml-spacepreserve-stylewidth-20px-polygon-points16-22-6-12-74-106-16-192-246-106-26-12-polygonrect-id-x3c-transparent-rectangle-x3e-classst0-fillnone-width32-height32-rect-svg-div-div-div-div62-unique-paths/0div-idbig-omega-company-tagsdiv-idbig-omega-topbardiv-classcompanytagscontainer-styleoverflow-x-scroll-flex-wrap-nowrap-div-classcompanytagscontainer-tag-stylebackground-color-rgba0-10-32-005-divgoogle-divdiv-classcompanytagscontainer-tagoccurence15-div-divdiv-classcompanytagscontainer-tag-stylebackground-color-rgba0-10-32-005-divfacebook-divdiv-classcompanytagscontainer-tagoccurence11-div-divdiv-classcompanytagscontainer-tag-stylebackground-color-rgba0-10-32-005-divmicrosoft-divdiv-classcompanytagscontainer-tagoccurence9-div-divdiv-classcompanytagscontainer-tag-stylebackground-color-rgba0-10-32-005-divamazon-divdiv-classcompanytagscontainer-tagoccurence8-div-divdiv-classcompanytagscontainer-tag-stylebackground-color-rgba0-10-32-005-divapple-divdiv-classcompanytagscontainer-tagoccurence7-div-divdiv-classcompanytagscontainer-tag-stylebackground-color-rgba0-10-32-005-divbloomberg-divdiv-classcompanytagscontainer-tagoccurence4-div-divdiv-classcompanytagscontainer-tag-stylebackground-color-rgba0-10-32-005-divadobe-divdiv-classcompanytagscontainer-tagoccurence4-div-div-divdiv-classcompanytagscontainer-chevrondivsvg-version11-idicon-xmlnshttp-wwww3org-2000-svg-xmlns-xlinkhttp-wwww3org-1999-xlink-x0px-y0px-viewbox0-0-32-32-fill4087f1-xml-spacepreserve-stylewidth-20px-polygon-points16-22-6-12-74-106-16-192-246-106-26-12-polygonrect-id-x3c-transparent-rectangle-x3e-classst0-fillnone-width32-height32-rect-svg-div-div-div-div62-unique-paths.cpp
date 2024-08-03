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
        int right = uniquePaths(i-1, j, dp);
        
        return (dp[i][j] = left + right);
    }
    
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return uniquePaths(m-1, n-1, dp);
    }
};