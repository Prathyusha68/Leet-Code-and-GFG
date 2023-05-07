class Solution {
    enum method
    {
        RECURSION_METHOD = 0,
        MEMORIZATION_METHOD = 1,
        TABULATION_METHOD = 2,
        OPTIMIZED_METHOD = 3
    };
    
    int recursion(int i, int j, int n, vector<vector<int>>& triangle)
    {
        if(i == n-1) return triangle[i][j];
        
        int down = triangle[i][j] + recursion(i+1, j, n, triangle);
        int diagnol = triangle[i][j] + recursion(i+1, j+1, n, triangle);
        
        return min(down, diagnol);
    }
    
    int memorization(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp)
    {
        if(i == n-1) return triangle[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = triangle[i][j] + memorization(i+1, j, n, triangle, dp);
        int diagnol = triangle[i][j] + memorization(i+1, j+1, n, triangle, dp);
        
        return dp[i][j] = min(down, diagnol);
    }
    
    int tabulation(vector<vector<int>>& triangle)
    {
        int n = triangle.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int j = 0; j < n; j++)
            dp[n-1][j] = triangle[n-1][j];
        
        for(int i = n-2; i >= 0; i--)
        {
            for(int j = i; j >= 0; j--)
            {
                int down = triangle[i][j] + dp[i+1][j];

                int diagnol = triangle[i][j] + dp[i+1][j+1];
        
                dp[i][j] = min(down, diagnol);
            }
        }
        
        return dp[0][0];
    }
    
    int optimization(vector<vector<int>>& triangle)
    {
        int n = triangle.size();

        vector<int> next(n+1, 0);
            
        for(int j = 0; j < n; j++)
            next[j] = triangle[n-1][j];
        
        for(int i = n-2; i >= 0; i--)
        {
            vector<int> curr(n+1, 0);
            for(int j = i; j >= 0; j--)
            {
                int down = triangle[i][j] + next[j];

                int diagnol = triangle[i][j] + next[j+1];
        
                curr[j] = min(down, diagnol);
            }
            next = curr;
        }
        
        return next[0];
    }
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
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
               int n = triangle.size();
               
               return recursion(0, 0, n, triangle);
               break;
           }
           case MEMORIZATION_METHOD :
           {
               /**
                *  Time Complexity : O(N * N) 
                *     (There are N*N states therefore at max ‘N*N’ new problems will be solved.)
                *  Space Complexity : O(N) + O(N * N)
                *     (We are using a recursion stack space(O(N)) and a 2D array
                *     (O(N * N)).)
                */
               int n = triangle.size();

               vector<vector<int>> dp(n, vector<int>(n, -1));
               
               return memorization(0, 0, n, triangle, dp);
               break;
           }
           case TABULATION_METHOD :
           {
               /**
                *  Time Complexity : O(N * N) 
                *     (There are two nested loops)
                *  Space Complexity : O(N * N)
                *     (We are using an external array of size ‘N * N’. Stack Space is
                *      eliminated.)
                */
               return tabulation(triangle);
               break;
           }
           case OPTIMIZED_METHOD :
           {
               /**
                *  Time Complexity : O(N * N) 
                *     (There are two nested loops)
                *  Space Complexity : O(N)
                *     (We are using an external array of size ‘N’ to store only one row.)
                */
               return optimization(triangle);
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