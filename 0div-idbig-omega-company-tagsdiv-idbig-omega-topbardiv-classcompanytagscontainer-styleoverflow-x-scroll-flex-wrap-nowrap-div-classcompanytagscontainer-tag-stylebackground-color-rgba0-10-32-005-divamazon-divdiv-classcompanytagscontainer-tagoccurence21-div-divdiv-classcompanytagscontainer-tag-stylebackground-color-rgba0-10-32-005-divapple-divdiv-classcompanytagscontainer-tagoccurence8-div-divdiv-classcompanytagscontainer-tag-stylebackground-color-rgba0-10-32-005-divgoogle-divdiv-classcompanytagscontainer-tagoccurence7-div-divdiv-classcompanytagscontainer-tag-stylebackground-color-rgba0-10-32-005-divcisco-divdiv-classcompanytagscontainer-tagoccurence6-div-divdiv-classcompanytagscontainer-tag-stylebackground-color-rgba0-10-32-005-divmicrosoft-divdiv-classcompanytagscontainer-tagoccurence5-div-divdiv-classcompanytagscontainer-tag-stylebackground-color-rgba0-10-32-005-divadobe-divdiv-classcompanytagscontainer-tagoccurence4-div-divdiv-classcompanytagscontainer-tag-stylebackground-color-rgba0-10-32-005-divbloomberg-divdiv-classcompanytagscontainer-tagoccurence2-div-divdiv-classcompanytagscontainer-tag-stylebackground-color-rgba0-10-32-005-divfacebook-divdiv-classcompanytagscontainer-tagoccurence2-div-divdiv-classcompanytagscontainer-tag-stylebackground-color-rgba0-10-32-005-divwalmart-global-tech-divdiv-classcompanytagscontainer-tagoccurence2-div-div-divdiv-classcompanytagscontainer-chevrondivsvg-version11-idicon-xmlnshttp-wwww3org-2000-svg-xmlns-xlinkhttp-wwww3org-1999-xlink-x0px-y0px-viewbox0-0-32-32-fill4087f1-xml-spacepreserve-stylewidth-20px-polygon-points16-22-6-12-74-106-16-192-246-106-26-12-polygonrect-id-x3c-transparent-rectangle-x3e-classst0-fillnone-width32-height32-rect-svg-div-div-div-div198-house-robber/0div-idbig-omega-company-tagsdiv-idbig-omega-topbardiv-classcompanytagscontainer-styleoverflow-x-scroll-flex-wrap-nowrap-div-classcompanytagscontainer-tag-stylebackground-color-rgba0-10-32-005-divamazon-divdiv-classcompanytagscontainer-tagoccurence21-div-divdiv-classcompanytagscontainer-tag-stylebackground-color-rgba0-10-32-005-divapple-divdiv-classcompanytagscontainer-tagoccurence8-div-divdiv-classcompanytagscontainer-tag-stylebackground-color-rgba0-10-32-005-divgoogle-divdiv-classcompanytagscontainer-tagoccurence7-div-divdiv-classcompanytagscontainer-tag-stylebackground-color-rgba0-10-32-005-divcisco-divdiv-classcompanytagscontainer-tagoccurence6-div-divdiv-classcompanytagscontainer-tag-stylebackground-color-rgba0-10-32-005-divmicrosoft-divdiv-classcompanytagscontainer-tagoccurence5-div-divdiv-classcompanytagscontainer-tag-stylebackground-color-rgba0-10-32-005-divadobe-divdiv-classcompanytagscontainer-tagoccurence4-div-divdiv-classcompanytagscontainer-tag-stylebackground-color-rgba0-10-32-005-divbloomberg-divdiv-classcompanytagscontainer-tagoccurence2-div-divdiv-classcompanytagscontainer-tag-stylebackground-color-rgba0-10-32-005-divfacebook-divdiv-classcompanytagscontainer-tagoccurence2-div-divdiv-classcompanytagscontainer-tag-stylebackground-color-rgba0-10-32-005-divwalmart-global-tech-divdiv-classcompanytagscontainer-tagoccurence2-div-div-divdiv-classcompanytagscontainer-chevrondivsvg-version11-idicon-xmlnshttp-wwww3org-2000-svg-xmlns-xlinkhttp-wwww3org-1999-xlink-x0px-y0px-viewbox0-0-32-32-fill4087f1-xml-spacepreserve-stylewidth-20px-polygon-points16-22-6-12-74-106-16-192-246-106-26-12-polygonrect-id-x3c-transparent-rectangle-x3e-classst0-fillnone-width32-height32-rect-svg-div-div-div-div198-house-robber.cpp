class Solution {
    int solveUtil(int ind, vector<int>& arr, vector<int>& dp) {
    
    // Base cases
    if (ind == 0) 
        return arr[ind];
    if (ind < 0)  
        return 0;
        
    // If the result for this index is already computed, return it
    if (dp[ind] != -1)
        return dp[ind];


    // Choose the current element or skip it, and take the maximum
    int pick = arr[ind] + solveUtil(ind - 2, arr, dp); // Choosing the current element
    int nonPick = 0 + solveUtil(ind - 1, arr, dp);      // Skipping the current element

    // Store the result in the DP table and return it
    return dp[ind] = max(pick, nonPick);
}
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() +1, -1);
        return solveUtil(nums.size()-1, nums, dp);
    }
};