class Solution {
    enum method
    {
        MEMORIZATION_METHOD = 0,
        TABULATION_METHOD = 1,
        OPTIMIZED_METHOD = 2
    };
    
    int memorization(int n, int i, vector<int> &dp)
    {
        if(i >= n)
        {
            if(i == n)
                return 1;
            else
                return 0;
        }
        
        if(dp[i] != -1)
            return dp[i];
        
        return (dp[i] = (memorization(n, i+1, dp) + memorization(n, i+2, dp)));
    }
    
    int tabulation(int n)
    {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    
    int optimization(int n)
    {
        int prev1 = 1;
        int prev2 = 1;

        for(int i = 2; i <= n; i++)
        {
            int curr = prev1+prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
public:
    int climbStairs(int n) {
       int type = 2;
       switch(type)
       {
           case MEMORIZATION_METHOD :
           {
               /**
                *  Time Complexity : O(N) 
                *     (There are N states therefore at max ‘N’ new problems will be solved.)
                *  Space Complexity : O(N) + O(N)
                *     (We are using a recursion stack space(O(N)) and a 1D array ( O(N)).)
                */
               vector<int> dp(n, -1);
               return memorization(n, 0, dp);
               break;
           }
           case TABULATION_METHOD :
           {
               /**
                *  Time Complexity : O(N) 
                *     (There is one loop)
                *  Space Complexity : O(N)
                *     (We are using an external array of size ‘N’. Stack Space is eliminated.)
                */
               return tabulation(n);
               break;
           }
           case OPTIMIZED_METHOD :
           {
               /**
                *  Time Complexity : O(N) 
                *     (There is one loop)
                *  Space Complexity : O(1)
                *     (We are using prev1, prev2 and curr variables.)
                */
               return optimization(n);
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