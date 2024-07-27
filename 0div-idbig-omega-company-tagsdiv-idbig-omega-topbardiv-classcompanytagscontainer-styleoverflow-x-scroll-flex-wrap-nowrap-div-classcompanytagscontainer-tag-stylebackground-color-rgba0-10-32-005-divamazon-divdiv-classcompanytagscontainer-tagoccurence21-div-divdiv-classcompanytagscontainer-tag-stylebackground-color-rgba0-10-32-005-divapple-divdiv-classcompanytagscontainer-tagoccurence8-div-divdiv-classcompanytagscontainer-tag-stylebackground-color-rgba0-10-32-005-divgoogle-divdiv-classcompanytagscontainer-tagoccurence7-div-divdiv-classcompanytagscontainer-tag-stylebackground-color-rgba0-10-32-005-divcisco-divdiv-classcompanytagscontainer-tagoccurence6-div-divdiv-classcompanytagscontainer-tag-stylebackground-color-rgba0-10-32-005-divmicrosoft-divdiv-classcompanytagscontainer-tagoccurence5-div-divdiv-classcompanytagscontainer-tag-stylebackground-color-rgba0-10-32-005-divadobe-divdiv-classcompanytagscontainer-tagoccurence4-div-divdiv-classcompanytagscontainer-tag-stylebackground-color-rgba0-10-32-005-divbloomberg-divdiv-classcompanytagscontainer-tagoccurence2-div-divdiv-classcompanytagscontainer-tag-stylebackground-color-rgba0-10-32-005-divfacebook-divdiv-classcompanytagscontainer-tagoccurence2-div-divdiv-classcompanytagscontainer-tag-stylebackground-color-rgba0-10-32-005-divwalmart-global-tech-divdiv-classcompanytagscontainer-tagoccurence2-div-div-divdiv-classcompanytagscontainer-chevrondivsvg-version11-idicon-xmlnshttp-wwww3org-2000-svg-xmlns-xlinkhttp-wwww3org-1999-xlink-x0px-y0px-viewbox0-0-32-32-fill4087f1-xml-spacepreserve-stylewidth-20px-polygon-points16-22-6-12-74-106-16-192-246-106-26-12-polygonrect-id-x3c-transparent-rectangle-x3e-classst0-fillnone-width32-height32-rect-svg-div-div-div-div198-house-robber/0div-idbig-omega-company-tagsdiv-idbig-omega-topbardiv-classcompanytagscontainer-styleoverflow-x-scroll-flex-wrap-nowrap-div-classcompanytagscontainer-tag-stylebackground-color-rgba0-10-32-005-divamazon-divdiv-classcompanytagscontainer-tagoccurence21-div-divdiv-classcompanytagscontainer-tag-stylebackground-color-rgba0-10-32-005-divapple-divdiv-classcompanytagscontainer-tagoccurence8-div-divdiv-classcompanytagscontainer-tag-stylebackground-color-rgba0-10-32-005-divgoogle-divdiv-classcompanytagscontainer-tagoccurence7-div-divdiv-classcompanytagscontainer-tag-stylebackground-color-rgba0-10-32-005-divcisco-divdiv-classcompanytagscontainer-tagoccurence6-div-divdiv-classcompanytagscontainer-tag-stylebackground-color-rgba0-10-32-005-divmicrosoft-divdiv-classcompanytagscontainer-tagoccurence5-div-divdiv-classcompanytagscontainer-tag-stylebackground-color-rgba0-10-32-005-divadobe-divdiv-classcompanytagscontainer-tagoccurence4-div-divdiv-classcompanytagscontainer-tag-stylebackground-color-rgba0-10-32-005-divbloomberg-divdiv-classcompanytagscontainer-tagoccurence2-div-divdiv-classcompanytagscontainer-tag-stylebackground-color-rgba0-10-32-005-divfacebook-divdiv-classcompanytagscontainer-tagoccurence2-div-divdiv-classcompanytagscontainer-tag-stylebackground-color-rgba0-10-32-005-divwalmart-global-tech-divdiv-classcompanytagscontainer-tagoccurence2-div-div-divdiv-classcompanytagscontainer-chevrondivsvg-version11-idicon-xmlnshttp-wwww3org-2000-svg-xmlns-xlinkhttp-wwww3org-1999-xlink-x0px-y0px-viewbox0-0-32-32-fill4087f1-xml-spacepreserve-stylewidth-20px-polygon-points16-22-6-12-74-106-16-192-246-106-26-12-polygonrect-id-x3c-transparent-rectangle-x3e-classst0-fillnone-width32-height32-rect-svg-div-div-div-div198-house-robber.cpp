class Solution {
    int solveUtil(int ind, vector<int>& arr, vector<int>& dp) {
    
    if (ind == 0) 
        return arr[ind];
        
    if (dp[ind] != -1)
        return dp[ind];

    int pick = arr[ind];
        
    if(ind-2 >= 0)
        pick += solveUtil(ind - 2, arr, dp);
        
    int nonPick = 0 + solveUtil(ind - 1, arr, dp);

    return dp[ind] = max(pick, nonPick);
}
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solveUtil(nums.size()-1, nums, dp);
    }
};