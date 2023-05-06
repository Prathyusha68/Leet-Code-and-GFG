#include<bits/stdc++.h>
class Solution {
    enum method
    {
        RECURSION_METHOD = 0,
        MEMORIZATION_METHOD = 1,
        TABULATION_METHOD = 2,
        OPTIMIZED_METHOD = 3
    };
    
    int recursion(int i, vector<int>& arr, int k)
    {
        int n = arr.size();
        if(i == n) return 0;
        
        int len = 0, maxSum = INT_MIN, maxVal = INT_MIN;
        
        for(int j = i; j < min(i+k, n); j++)
        {
            len++;
            maxVal = max(arr[j], maxVal);
            
            int sum = (len * maxVal) + recursion(j+1, arr, k);
            
            maxSum = max(maxSum, sum);            
        }
        
        return maxSum;
    }
    
    int memorization(int i, vector<int>& arr, int k, vector<int> &dp)
    {
        int n = arr.size();
        if(i == n) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int len = 0, maxSum = INT_MIN, maxVal = INT_MIN;
        
        for(int j = i; j < min(i+k, n); j++)
        {
            len++;
            maxVal = max(arr[j], maxVal);
            
            int sum = (len * maxVal) + recursion(j+1, arr, k);
            
            maxSum = max(maxSum, sum);            
        }
        
        return dp[i] = maxSum;
    }
    
    int tabulation(vector<int>& arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        
        for(int i = n-1; i >= 0; i--)
        {
            int len = 0, maxSum = INT_MIN, maxVal = INT_MIN;

            for(int j = i; j < min(i+k, n); j++)
            {
                len++;
                maxVal = max(arr[j], maxVal);

                int sum = (len * maxVal) + dp[j+1];

                maxSum = max(maxSum, sum); 
            } 
            dp[i] = maxSum;
        }
        return dp[0];
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
      int type = 2;
       switch(type)
       {
           case RECURSION_METHOD :
           {
               /**
                *  Time Complexity : Exponential
                *  Space Complexity : O(N)
                *     (We are using a recursion stack space(O(N)).)
                */

               return recursion(0, arr, k);
               break;
           }
           case MEMORIZATION_METHOD :
           {
               /**
                *  Time Complexity : O(N * k) 
                *     (There are a total of N states and for each state, we are running a loop
                *      from 0 to k..)
                *  Space Complexity : O(N) + O(N)
                *     (We are using a recursion stack space(O(N)) and a 1D array ( O(N)).)
                */
               
               vector<int> dp(arr.size(), -1);
               return memorization(0, arr, k, dp);
               break;
           }
           case TABULATION_METHOD :
           {
               /**
                *  Time Complexity : O(N * k) 
                *     (There are a total of N states and for each state, we are running a loop
                *      from 0 to k.)
                *  Space Complexity : O(N)
                *     (We are using an external array of size ‘N’. Stack Space is eliminated.)
                */
               
               return tabulation(arr, k);
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