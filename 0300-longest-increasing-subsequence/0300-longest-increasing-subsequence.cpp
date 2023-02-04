class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxLen = 1;
        vector<int> dp(nums.size()+1, 1);
        
        for(int curr = 1; curr < nums.size(); curr++)
        {
            for(int prev = 0; prev < curr; prev++)
            {
                if((nums[curr] > nums[prev]) && (dp[curr] < dp[prev]+1))
                    dp[curr] = 1 + dp[prev];
            }
            
            maxLen = max(maxLen, dp[curr]);
        }
        
        return maxLen;
    }
};