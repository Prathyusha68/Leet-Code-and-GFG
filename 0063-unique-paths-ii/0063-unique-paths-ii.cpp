class Solution {
    enum method
    {
        RECURSION_METHOD = 0,
        MEMORIZATION_METHOD = 1,
        TABULATION_METHOD = 2,
        OPTIMIZED_METHOD = 3
    };
    
    int recursion(int i, int j, int m, int n, vector<vector<int>>& obstacleGrid)
    {
        if((i < 0) || (i >= m) || (j < 0) || (j >= n)) return 0;
        
        if(obstacleGrid[i][j] == 1) return 0;
        
        if((i == 0) && (j == 0)) return 1;
        
        int up = recursion(i-1, j, m, n, obstacleGrid);
        int left = recursion(i, j-1, m, n, obstacleGrid);
        
        return up + left;
    }
    
    int memorization(int i, int j, int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp)
    {
        if((i < 0) || (i >= m) || (j < 0) || (j >= n)) return 0;
        
        if(obstacleGrid[i][j] == 1) return 0;
        
        if((i == 0) && (j == 0)) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = recursion(i-1, j, m, n, obstacleGrid);
        int left = recursion(i, j-1, m, n, obstacleGrid);
        
        return dp[i][j] = up + left;
    }
    
    int tabulation(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0; 
                    continue;
                }
                
                if((i == 0) && (j == 0))
                {
                    dp[i][j] = 1;
                    continue;
                }
                
                int up = 0;
                if(i-1 >= 0)
                    up = dp[i-1][j];
                
                int left = 0;
                if(j-1 >= 0)
                    left = dp[i][j-1];

                dp[i][j] = up + left;
            }
        }
        
        return dp[m-1][n-1];
    }
    
    int optimization(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<int> prev(n, 0);
        
        for(int i = 0; i < m; i++)
        {
            vector<int> curr(n, 0);
            for(int j = 0; j < n; j++)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    curr[j] = 0; 
                    continue;
                }
                
                if((i == 0) && (j == 0))
                {
                    curr[j] = 1;
                    continue;
                }
                
                int up = 0;
                if(i-1 >= 0)
                    up = prev[j];
                
                int left = 0;
                if(j-1 >= 0)
                    left = curr[j-1];

                curr[j] = up + left;
            }
            prev = curr;
        }
        
        return prev[n-1];
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       int type = 3;
       switch(type)
       {
           case RECURSION_METHOD :
           {
               /**
                *  Time Complexity : O(2^N) 
                *  Space Complexity : O(N)
                *     (We are using a recursion stack space(O(N)).)
                */
               int m = obstacleGrid.size();
               int n = obstacleGrid[0].size();
               
               return recursion(m-1, n-1, m, n, obstacleGrid);
               break;
           }
           case MEMORIZATION_METHOD :
           {
               /**
                *  Time Complexity : O(N * N) 
                *     (There are N*N states therefore at max ‘N*N’ new problems will be solved.)
                *  Space Complexity : O(N * N) + O(N)
                *     (We are using a recursion stack space(O(N)) and a 2D array ( O(N*N)).)
                */
               int m = obstacleGrid.size();
               int n = obstacleGrid[0].size();
               vector<vector<int>> dp(m, vector<int>(n, -1));
               
               return memorization(m-1, n-1, m, n, obstacleGrid, dp);
               break;
           }
           case TABULATION_METHOD :
           {
               /**
                *  Time Complexity : O(N * N) 
                *     (There are two nested loops)
                *  Space Complexity : O(N)
                *     (We are using an external array of size ‘N’. Stack Space is eliminated.)
                */
               return tabulation(obstacleGrid);
               break;
           }
           case OPTIMIZED_METHOD :
           {
               /**
                *  Time Complexity : O(N * W) 
                *     (There are two nested loops)
                *  Space Complexity : O(N * W)
                *     (We are using an external array of size ‘W+1’ to store only one row.)
                */
               return optimization(obstacleGrid);
               break;
           }
           default:
           {
               cout<<"Invalid Method type"<<endl;
           }
       }
       return 0; 
    }
};