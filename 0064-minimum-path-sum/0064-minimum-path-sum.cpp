class Solution {
    enum method
    {
        RECURSION_METHOD = 0,
        MEMORIZATION_METHOD = 1,
        TABULATION_METHOD = 2,
        OPTIMIZED_METHOD = 3
    };
    
    int recursion(int i, int j, int n, int m, vector<vector<int>>& grid)
    {
        if((i == 0) && (j == 0)) return grid[i][j];
        
        if((i < 0) || (j < 0)) return 1e9;
        
        int up = grid[i][j] + recursion(i-1, j, n, m, grid);
        int left = grid[i][j] + recursion(i, j-1, n, m, grid);
        
        return min(up, left);
    }
    
    int memorization(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if((i == 0) && (j == 0)) return grid[i][j];
        
        if((i < 0) || (j < 0)) return 1e9;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = grid[i][j] + recursion(i-1, j, n, m, grid);
        int left = grid[i][j] + recursion(i, j-1, n, m, grid);
        
        return dp[i][j] = min(up, left);
    }
    
    int tabulation(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if((i == 0) && (j == 0))
                {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                
                int up = grid[i][j];
                if(i-1 >= 0)
                    up += dp[i-1][j];
                else
                    up = 1e9;
                
                int left = grid[i][j];
                if(j-1 >= 0)
                    left += dp[i][j-1];
                else
                    left = 1e9;
        
                dp[i][j] = min(up, left);
            }
        }
        
        return dp[n-1][m-1];
    }
    
    int optimization(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> prev(m, 0);
        
        for(int i = 0; i < n; i++)
        {
            vector<int> curr(m, 0);
            for(int j = 0; j < m; j++)
            {
                if((i == 0) && (j == 0))
                {
                    curr[j] = grid[i][j];
                    continue;
                }
                
                int up = grid[i][j];
                if(i-1 >= 0)
                    up += prev[j];
                else
                    up = 1e9;
                
                int left = grid[i][j];
                if(j-1 >= 0)
                    left += curr[j-1];
                else
                    left = 1e9;
        
                curr[j] = min(up, left);
            }
            prev = curr;
        }
        
        return prev[m-1];
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
       int type = 3;
       switch(type)
       {
           case RECURSION_METHOD :
           {
               /**
                *  Time Complexity : Exponentional  
                *  Space Complexity : O(N * M)
                *     (We are using a recursion stack space(O(N * M)).)
                */
               int n = grid.size();
               int m = grid[0].size();
               
               return recursion(n-1, m-1, n, m, grid);
               break;
           }
           case MEMORIZATION_METHOD :
           {
               /**
                *  Time Complexity : O(N * M) 
                *     (There are N*N states therefore at max ‘N*N’ new problems will be solved.)
                *  Space Complexity : O(N-1 * M-1) + O(N * M)
                *     (We are using a recursion stack space(O(N * M)) and a 2D array
                *     (O(N-1 * M-1)).)
                */
               int n = grid.size();
               int m = grid[0].size();
               vector<vector<int>> dp(n, vector<int>(m, -1));
               
               return memorization(n-1, m-1, n, m, grid, dp);
               break;
           }
           case TABULATION_METHOD :
           {
               /**
                *  Time Complexity : O(N * M) 
                *     (There are two nested loops)
                *  Space Complexity : O(N * M)
                *     (We are using an external array of size ‘N * M’. Stack Space is
                *      eliminated.)
                */
               return tabulation(grid);
               break;
           }
           case OPTIMIZED_METHOD :
           {
               /**
                *  Time Complexity : O(N * M) 
                *     (There are two nested loops)
                *  Space Complexity : O(N)
                *     (We are using an external array of size ‘N’ to store only one row.)
                */
               return optimization(grid);
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