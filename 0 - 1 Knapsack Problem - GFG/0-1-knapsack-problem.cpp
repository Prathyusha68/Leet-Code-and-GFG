//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    enum method
    {
        MEMORIZATION_METHOD = 0,
        TABULATION_METHOD = 1,
        OPTIMIZED_METHOD = 2
    };
    
    int memorization(int W, int wt[], int val[], int index, vector<vector<int>> &dp) 
    { 
         if(index == 0)
         {
             if(wt[0] <= W) return val[0];
             
             return 0;
         }
         
         if(dp[index][W] != -1) return dp[index][W];
         
         int notTake = 0 + memorization(W, wt, val, index-1, dp);
         
         int take = INT_MIN;
         if(W-wt[index] >= 0)
            take = val[index] + memorization(W-wt[index], wt, val, index-1, dp);
            
        return dp[index][W] = max(take, notTake);
    }
    
    int tabulation(int W, int wt[], int val[], int n) 
    {
        vector<vector<int>> dp(n, vector<int>(W+1, 0));
        
        for(int i = wt[0]; i <= W; i++)
           dp[0][i] = val[0];
        
        for(int i = 1; i < n; i++)
        {
            for(int cap = 0; cap <= W; cap++)
            {
                int notTake = 0 + dp[i-1][cap];

                int take = INT_MIN;
                if(cap >= wt[i])
                    take = val[i] + dp[i-1][cap-wt[i]];
                    
                dp[i][cap] = max(take, notTake);
            }
        }
        
        return dp[n-1][W];
        
    }
    
    int optimization(int W, int wt[], int val[], int n) 
    {
        vector<int> prev(W+1, 0);
        
        for(int i = wt[0]; i <= W; i++)
           prev[i] = val[0];
        
        for(int i = 1; i < n; i++)
        {
            for(int cap = W; cap >= 0; cap--)
            {
                int notTake = 0 + prev[cap];

                int take = INT_MIN;
                if(cap >= wt[i])
                    take = val[i] + prev[cap-wt[i]];
                    
                prev[cap] = max(take, notTake);
            }
        }
        
        return prev[W];
        
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       int type = 2;
       switch(type)
       {
           case MEMORIZATION_METHOD :
           {
               /**
                *  Time Complexity : O(N * W) 
                *     (There are N*W states therefore at max ‘N*W’ new problems will be solved.)
                *  Space Complexity : O(N * W) + O(N)
                *     (We are using a recursion stack space(O(N)) and a 2D array ( O(N*W)).)
                */
               vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
               return memorization(W, wt, val, n-1, dp);
               break;
           }
           case TABULATION_METHOD :
           {
               /**
                *  Time Complexity : O(N * W) 
                *     (There are two nested loops)
                *  Space Complexity : O(N * W)
                *     (We are using an external array of size ‘N*W’. Stack Space is eliminated.)
                */
               return tabulation(W, wt, val, n);
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
               return optimization(W, wt, val, n);
               break;
           }
           default:
           {
               cout<<"Invalid Method type"<<endl;
           }
       }
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends