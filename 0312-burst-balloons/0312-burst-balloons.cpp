class Solution {
    enum method
    {
        RECURSION_METHOD = 0,
        MEMORIZATION_METHOD = 1,
        TABULATION_METHOD = 2,
        OPTIMIZED_METHOD = 3
    };
    
    int recursion(int i, int j, vector<int>& nums)
    {
        if(i > j) return 0;
        
        int maxCoins = INT_MIN;
        for(int k = i; k <= j; k++)
        {
            int numCoins = nums[i-1] * nums[k] * nums[j+1] +
                recursion(i, k-1, nums) + recursion(k+1, j, nums);
            
            maxCoins = max(maxCoins, numCoins);
        }
        
        return maxCoins;
    }
    
    int memorization(int i, int j, vector<int>& nums, vector<vector<int>> &dp)
    {
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int maxCoins = INT_MIN;
        for(int k = i; k <= j; k++)
        {
            int numCoins = nums[i-1] * nums[k] * nums[j+1] +
                memorization(i, k-1, nums, dp) + memorization(k+1, j, nums, dp);
            
            maxCoins = max(maxCoins, numCoins);
        }
        
        return dp[i][j] = maxCoins;
    }
    
    int tabulation(vector<int>& nums)
    {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        
        for(int i = n; i >= 1; i--)
        {
            for(int j = 1; j <= n; j++)
            {
                if(i > j) continue;
                
                int maxCoins = INT_MIN;
                for(int k = i; k <= j; k++)
                {
                    int numCoins = nums[i-1] * nums[k] * nums[j+1] +
                       dp[i][k-1] + dp[k+1][j];

                    maxCoins = max(maxCoins, numCoins);
                }

                dp[i][j] = maxCoins;
            }
        }
        
        return dp[1][n];
    }
    
public:
    int maxCoins(vector<int>& nums) {
        int type = 1;
       switch(type)
       {
           case RECURSION_METHOD :
           {
               /**
                *  Time Complexity : O(2^N * N) Exponential
                *  Space Complexity : O(N)
                *     (We are using a recursion stack space(O(N)).)
                */
               int n = nums.size();
               nums.push_back(1);
               nums.insert(nums.begin(), 1);
               return recursion(1, n, nums);
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
               int n = nums.size();
               
               nums.push_back(1);
               nums.insert(nums.begin(), 1);
               vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
               return memorization(1, n, nums, dp);
               break;
           }
           case TABULATION_METHOD :
           {
               /**
                *  Time Complexity : O(N * N) 
                *     (There are 2 variables i and j, therefore, N*N states and we explicitly
                *      run a loop inside the function which will run for N times, therefore at
                *      max ‘N*N*N’ new problems will be solved.)
                *  Space Complexity : O(N * N)
                *     (We are using an external array of size ‘N * N’. Stack Space is
                *      eliminated.)
                */

               return tabulation(nums);
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