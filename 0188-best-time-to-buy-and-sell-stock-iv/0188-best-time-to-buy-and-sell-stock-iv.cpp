class Solution {
     enum method
    {
        RECURSION_METHOD = 0,
        MEMORIZATION_METHOD = 1,
        TABULATION_METHOD = 2,
        OPTIMIZED_METHOD = 3
    };
    
    int recursion(int ind, int transactions, int k, vector<int>& prices)
    {
        if(transactions == 2*k) return 0;
        
        if(ind == prices.size()) return 0;
        
        if(transactions%2 == 0)
        {
            return max((-prices[ind] + recursion(ind+1, transactions+1, k, prices)),
                      (0 + recursion(ind+1, transactions, k, prices)));
        }
                       
        return max((prices[ind] + recursion(ind+1, transactions+1, k, prices)),
                  (0 + recursion(ind+1, transactions, k, prices)));
    }
     
    int memorization(int ind, int transactions, int k, vector<int>& prices, vector<vector<int>> &dp)
    {
        if(transactions == 2*k) return 0;
        
        if(ind == prices.size()) return 0;
        
        if(dp[ind][transactions] != -1) return dp[ind][transactions];

        if(transactions%2 == 0)
        {
            return dp[ind][transactions] = max((-prices[ind] + memorization(ind+1, transactions+1, k, prices, dp)),
                      (0 + memorization(ind+1, transactions, k, prices, dp)));
        }
          
        return dp[ind][transactions] = max((prices[ind] + memorization(ind+1, transactions+1, k, prices, dp)), (0 + memorization(ind+1, transactions, k, prices, dp)));
    }
    
    int tabulation(vector<int>& prices, int k)
    {
        int n = prices.size();

        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));
        
        for(int ind = n-1; ind >= 0; ind--)
        {
            for(int transactions = 2*k -1; transactions >= 0; transactions--)
            {
                if(transactions%2 == 0)
                {
                    dp[ind][transactions] = max((-prices[ind] + dp[ind+1][transactions+1]),
                                                 (0 + dp[ind+1][transactions]));
                }
                else
                {
                    dp[ind][transactions] = max((prices[ind] + dp[ind+1][transactions+1]),
                                                 (0 + dp[ind+1][transactions]));
                }
            }
        }
        
        return dp[0][0];
    }
    
    int optimization(vector<int>& prices, int k)
    {
        int n = prices.size();

        vector<int> next(2*k+1, 0);
        vector<int> curr(2*k+1, 0);
        for(int ind = n-1; ind >= 0; ind--)
        {
            for(int transactions = 2*k -1; transactions >= 0; transactions--)
            {
                if(transactions%2 == 0)
                {
                    curr[transactions] = max((-prices[ind] + next[transactions+1]),
                                                 (0 + next[transactions]));
                }
                else
                {
                    curr[transactions] = max((prices[ind] + next[transactions+1]),
                                                 (0 + next[transactions]));
                }
            }
            next = curr;
        }
        
        return next[0];
    }
    
public:
    int maxProfit(int k, vector<int>& prices) {
       int type = 2;
       switch(type)
       {
           case RECURSION_METHOD :
           {
               /**
                *  Time Complexity : Exponentional  
                *  Space Complexity : O(N)
                *     (We are using a recursion stack space(O(N)).)
                */
               
               return recursion(0, 0, k, prices);
               break;
           }
           case MEMORIZATION_METHOD :
           {
               /**
                *  Time Complexity : O(N * 2 * k) 
                *     (There are N*2 states therefore at max ‘N*2’ new problems will be solved.)
                *  Space Complexity : O(N) + O(N * 2 * k)
                *     (We are using a recursion stack space(O(N)) and a 2D array
                *     (O(N * 2 * k)).)
                */
               int n = prices.size();

               vector<vector<int>> dp(n+1, vector<int>(2*k, -1));
               
               return memorization(0, 0, k, prices, dp);
               break;
           }
           case TABULATION_METHOD :
           {
               /**
                *  Time Complexity : O(N * 2 * k) 
                *     (There are two nested loops)
                *  Space Complexity : O(N * 2 * k)
                *     (We are using an external array of size ‘N * 2 * k’. Stack Space is
                *      eliminated.)
                */
               return tabulation(prices, k);
               break;
           }
           case OPTIMIZED_METHOD :
           {
               /**
                *  Time Complexity : O(N * 2 * k) 
                *     (There are two nested loops)
                *  Space Complexity : O(2 * k + 1)
                *     (We are using an external array of size ‘2 * k + 1’ to store only one row.)
                */
               return optimization(prices, k);
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