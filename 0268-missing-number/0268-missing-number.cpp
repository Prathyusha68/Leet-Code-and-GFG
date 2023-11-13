class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int numSum = n*(n+1)/2;
        int totalSum = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            totalSum += nums[i];
        }

        return (numSum-totalSum);
    }
};