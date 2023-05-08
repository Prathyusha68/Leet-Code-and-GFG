class Solution {
    enum method
    {
        RECURSION_METHOD = 0,
        MEMORIZATION_METHOD = 1,
        TABULATION_METHOD = 2,
        OPTIMIZED_METHOD = 3
    };
    
    int recursion(int ind, int buy, vector<int>& prices)
    {
        if(ind == prices.size()) return 0;
        
        if(buy)
        {
            return max((-prices[ind] + recursion(ind+1, 0, prices)),
                      (0 + recursion(ind+1, 1, prices)));
        }
                       
        return max((prices[ind] + recursion(ind+1, 1, prices)),
                  (0 + recursion(ind+1, 0, prices)));
    }
    
    int memorization(int ind, int buy, vector<int>& prices, vector<vector<int>> &dp)
    {
        if(ind == prices.size()) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];
        
        if(buy)
        {
            return dp[ind][buy] = max((-prices[ind] + memorization(ind+1, 0, prices, dp)),
                      (0 + memorization(ind+1, 1, prices, dp)));
        }

        return dp[ind][buy] = max((prices[ind] + memorization(ind+1, 1, prices, dp)),
                  (0 + memorization(ind+1, 0, prices, dp)));
    }
    
    int tabulation(vector<int>& prices)
    {
        int n = prices.size();

        vector<vector<int>> dp(n+1, vector<int>(3, 0));
        
        for(int ind = n-1; ind >= 0; ind--)
        {
             dp[ind][1] = max((-prices[ind] + dp[ind+1][0]),
                          (0 + dp[ind+1][1]));

             dp[ind][0] = max((prices[ind] + dp[ind+1][1]),
                          (0 + dp[ind+1][0]));
        }
        
        return dp[0][1];
    }
    
    int optimization(vector<int>& prices)
    {
        int n = prices.size();

        vector<int> next(3, 0);
        vector<int> curr(3, 0);
        
        for(int ind = n-1; ind >= 0; ind--)
        {
             curr[1] = max((-prices[ind] + next[0]),
                          (0 + next[1]));

             curr[0] = max((prices[ind] + next[1]),
                          (0 + next[0]));
            next = curr;
        }
        
        return next[1];
    }
    
    
public:
    int maxProfit(vector<int>& prices) {
       int type = 3;
       switch(type)
       {
           case RECURSION_METHOD :
           {
               /**
                *  Time Complexity : Exponentional  
                *  Space Complexity : O(N)
                *     (We are using a recursion stack space(O(N)).)
                */
               
               return recursion(0, 1, prices);
               break;
           }
           case MEMORIZATION_METHOD :
           {
               /**
                *  Time Complexity : O(N * 2) 
                *     (There are N*2 states therefore at max ‘N*2’ new problems will be solved.)
                *  Space Complexity : O(N) + O(N * 2)
                *     (We are using a recursion stack space(O(N)) and a 2D array
                *     (O(N * 2)).)
                */
               int n = prices.size();

               vector<vector<int>> dp(n+1, vector<int>(2, -1));
               
               return memorization(0, 1, prices, dp);
               break;
           }
           case TABULATION_METHOD :
           {
               /**
                *  Time Complexity : O(N * 2) 
                *     (There are two nested loops)
                *  Space Complexity : O(N * 2)
                *     (We are using an external array of size ‘N * 2’. Stack Space is
                *      eliminated.)
                */
               return tabulation(prices);
               break;
           }
           case OPTIMIZED_METHOD :
           {
               /**
                *  Time Complexity : O(N * 2) 
                *     (There are two nested loops)
                *  Space Complexity : O(1)
                *     (We are using an external array of size ‘2’ to store only one row.)
                */
               return optimization(prices);
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