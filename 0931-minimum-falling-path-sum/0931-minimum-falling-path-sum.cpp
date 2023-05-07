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
        if((j < 0) || (j >= m)) return 1e9;
     
        if(i == 0) return grid[i][j];
        
        int up = grid[i][j] + recursion(i-1, j, n, m, grid);
        int ld = grid[i][j] + recursion(i-1, j-1, n, m, grid);
        int rd = grid[i][j] + recursion(i-1, j+1, n, m, grid);
        
        return min(up, min(ld, rd));
    }
    
    int memorization(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {   
        if((j < 0) || (j >= m)) return 1e9;
     
        if(i == 0) return grid[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = grid[i][j] + memorization(i-1, j, n, m, grid, dp);
        int ld = grid[i][j] + memorization(i-1, j-1, n, m, grid, dp);
        int rd = grid[i][j] + memorization(i-1, j+1, n, m, grid, dp);
        
        return dp[i][j] = min(up, min(ld, rd));
    }
    
    int tabulation(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for(int i = 0; i < m; i++)
            dp[0][i] = grid[0][i];
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int up = grid[i][j];
                if(i-1 >= 0)
                    up += dp[i-1][j];
                else
                    up = 1e9;
                
                int ld = grid[i][j];
                if(i-1 >= 0 && (j-1 >= 0))
                    ld += dp[i-1][j-1];
                else
                    ld = 1e9;
                
                int rd = grid[i][j];
                if(i-1 >= 0 && (j+1 < m))
                    rd += dp[i-1][j+1];
                else
                    rd = 1e9;
        
                dp[i][j] = min(up, min(ld, rd));
            }
        }
        
        int mini = INT_MAX;
        for(int k = 0; k < m; k++)
        {
           mini = min(mini, dp[n-1][k]);
        }
               
        return mini;
    }
    
    int optimization(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> prev(m, 0);
        
        for(int i = 0; i < m; i++)
            prev[i] = grid[0][i];
        
        for(int i = 1; i < n; i++)
        {
            vector<int> curr(m, 0);
            for(int j = 0; j < m; j++)
            {
                int up = grid[i][j];
                if(i-1 >= 0)
                    up += prev[j];
                else
                    up = 1e9;
                
                int ld = grid[i][j];
                if(i-1 >= 0 && (j-1 >= 0))
                    ld += prev[j-1];
                else
                    ld = 1e9;
                
                int rd = grid[i][j];
                if(i-1 >= 0 && (j+1 < m))
                    rd += prev[j+1];
                else
                    rd = 1e9;
        
                curr[j] = min(up, min(ld, rd));
            }
            prev = curr;
        }
        
        int mini = INT_MAX;
        for(int k = 0; k < m; k++)
        {
           mini = min(mini, prev[k]);
        }
               
        return mini;
    }
    
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
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
               int n = matrix.size();
               int m = matrix[0].size();
               int mini = INT_MAX;
               for(int i = 0; i < n; i++)
               {
                    mini = min(mini, recursion(n-1, i, n, m, matrix));
               }
               
               return mini;
               break;
           }
           case MEMORIZATION_METHOD :
           {
               /**
                *  Time Complexity : O(N * M) 
                *     (There are N*N states therefore at max ‘N*N’ new problems will be solved.)
                *  Space Complexity : O(N * M) + O(N * M)
                *     (We are using a recursion stack space(O(N * M)) and a 2D array
                *     (O(N * M)).)
                */
               int n = matrix.size();
               int m = matrix[0].size();
               vector<vector<int>> dp(n, vector<int>(m, -1));
               int mini = INT_MAX;
               
               for(int i = 0; i < n; i++)
               {
                    mini = min(mini, memorization(n-1, i, n, m, matrix, dp));
               }
               
               return mini;
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
               return tabulation(matrix);
               break;
           }
           case OPTIMIZED_METHOD :
           {
               /**
                *  Time Complexity : O(N * M) 
                *     (There are two nested loops)
                *  Space Complexity : O(M)
                *     (We are using an external array of size ‘M’ to store only one row.)
                */
               return optimization(matrix);
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