class Solution {
public:
    enum method
    {
        RECURSION_METHOD = 0,
        MEMORIZATION_METHOD = 1,
        TABULATION_METHOD = 2,
        OPTIMIZED_METHOD = 3
    };

    int recursion(int indx, int prevIndx, int n, vector<int>& nums) {
        if(indx == n) return 0;

        int len = recursion(indx+1, prevIndx, n, nums);

        if((prevIndx == -1) || (nums[indx] > nums[prevIndx]))
            len = max(len, 1+recursion(indx+1, indx, n, nums));

        return len;
    }

    int memorization(int indx, int prevIndx, int n, vector<int>& nums, vector<vector<int>> &dp) {
        if(indx == n) return 0;

        if(dp[indx][prevIndx+1] != -1)
            return dp[indx][prevIndx+1];

        int len = memorization(indx+1, prevIndx, n, nums, dp);

        if((prevIndx == -1) || (nums[indx] > nums[prevIndx]))
            len = max(len, 1+memorization(indx+1, indx, n, nums, dp));

        return dp[indx][prevIndx+1] = len;
    }

    int tabulation(int n, vector<int>& nums) {
        vector<int> dp(n, 1);

        int maxi = 1;
        for(int indx = 0; indx < n; indx++)
        {
            for(int prevIndx = 0; prevIndx <= indx; prevIndx++)
            {
                if(nums[indx] > nums[prevIndx])
                    dp[indx] = max(dp[indx], 1+dp[prevIndx]);
            }
            maxi = max(maxi, dp[indx]);
        }
        return maxi;
    }

    int lengthOfLIS(vector<int>& nums) {
       int type = 2;
       switch(type)
       {
           case RECURSION_METHOD :
           {
               /**
                *  Time Complexity : O(2^N) 
                *  Space Complexity : O(N)
                *     (We are using a recursion stack space(O(N)).)
                */
               return recursion(0, -1, nums.size(), nums);
               break;
           }
           case MEMORIZATION_METHOD :
           {
               /**
                *  Time Complexity : O(N * N) 
                *     (There are N*N states therefore at max ‘N*N’ new problems will be solved.)
                *  Space Complexity : O(N * N) + O(N)
                *     (We are using a recursion stack space(O(N)) and a 2D array ( O(N*N)).)
                */
               vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
               return memorization(0, -1, nums.size(), nums, dp);
               break;
           }
           case TABULATION_METHOD :
           {
               /**
                *  Time Complexity : O(N * N) 
                *     (There are two nested loops)
                *  Space Complexity : O(N)
                *     (We are using an external array of size ‘N’. Stack Space is eliminated.)
                */
               return tabulation(nums.size(), nums);
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