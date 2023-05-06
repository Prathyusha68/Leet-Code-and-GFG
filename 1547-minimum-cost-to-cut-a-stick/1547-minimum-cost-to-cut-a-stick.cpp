class Solution {
    
    enum method
    {
        RECURSION_METHOD = 0,
        MEMORIZATION_METHOD = 1,
        TABULATION_METHOD = 2,
        OPTIMIZED_METHOD = 3
    };
    
    int recursion(int i, int j, vector<int>& cuts)
    {
        if (i > j) return 0;
        
        int minCost = INT_MAX;
        
        for(int k = i; k <= j; k++)
        {
            int cost = (cuts[j+1] - cuts[i-1])
                + recursion(i, k-1, cuts)
                + recursion(k+1, j, cuts);
            
            minCost = min(cost, minCost);
        }
        
        return minCost;
    }
    
    int memorization(int i, int j, vector<int>& cuts, vector<vector<int>> &dp)
    {
        if (i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int minCost = INT_MAX;
        
        for(int k = i; k <= j; k++)
        {
            int cost = (cuts[j+1] - cuts[i-1])
                + memorization(i, k-1, cuts, dp)
                + memorization(k+1, j, cuts, dp);
            
            minCost = min(cost, minCost);
        }

        return dp[i][j] = minCost;
    }
    
    int tabulation(vector<int>& cuts, int c)
    {
        vector<vector<int>> dp(c+2, vector<int>(c+2, 0));
    
        for(int i = c; i >= 1; i--)
        {
            for(int j = 1; j <= c; j++)
            {
                if(i > j) continue;
                
                int minCost = INT_MAX;
        
                for(int k = i; k <= j; k++)
                {
                    int cost = (cuts[j+1] - cuts[i-1])
                        + dp[i][k-1]
                        + dp[k+1][j];

                    minCost = min(cost, minCost);
                }
                dp[i][j] = minCost;
            }            
        }
        
        return dp[1][c];
    }
    
public:
    int minCost(int n, vector<int>& cuts) {
       int type = 2;
       switch(type)
       {
           case RECURSION_METHOD :
           {
               /**
                *  Time Complexity : O(2^N * N) Exponential
                *  Space Complexity : O(N)
                *     (We are using a recursion stack space(O(N)).)
                */
               int c = cuts.size();

               cuts.push_back(n);
               cuts.insert(cuts.begin(), 0);
               sort(cuts.begin(), cuts.end());

               return recursion(1, c, cuts);
               break;
           }
           case MEMORIZATION_METHOD :
           {
               /**
                *  Time Complexity : O(N * N * N) 
                *     (There are 2 variables i and j, therefore, N*N states and we explicitly
                *      run a loop inside the function which will run for N times, therefore at
                *      max ‘N*N*N’ new problems will be solved.)
                *  Space Complexity : O(N * N) + O(N)
                *     (We are using a recursion stack space(O(N)) and a 2D array ( O(N*N)).)
                */
               int c = cuts.size();
               
               cuts.push_back(n);
               cuts.insert(cuts.begin(), 0);
               sort(cuts.begin(), cuts.end());
               
               vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
               return memorization(1, c, cuts, dp);
               break;
           }
           case TABULATION_METHOD :
           {
               /**
                *  Time Complexity : O(N * N) 
                *     (There are 2 variables i and j, therefore, N*N states and we explicitly
                *      run a loop inside the function which will run for N times, therefore at
                *      max ‘N*N*N’ new problems will be solved.)
                *  Space Complexity : O(N)
                *     (We are using an external array of size ‘N’. Stack Space is eliminated.)
                */
               int c = cuts.size();
               
               cuts.push_back(n);
               cuts.insert(cuts.begin(), 0);
               sort(cuts.begin(), cuts.end());
               return tabulation(cuts, c);
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