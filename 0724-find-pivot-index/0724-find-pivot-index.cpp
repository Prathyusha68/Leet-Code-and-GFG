class Solution {
public:
    int pivotIndex(vector<int>& nums) {\
        int n = nums.size();
        vector<int> rightSum(n, 0), leftSum(n, 0);
        int right =nums[n-1], left = nums[0];
        
        for(int i = 1; i < n; i++)
        {
            leftSum[i] = left;
            left += nums[i];
        }
                                       
        for(int i = n-2; i >= 0; i--)
        {
            rightSum[i] = right;
            right += nums[i];
        }
                                       
        for(int i = 0; i < n; i++)
        {
            if(leftSum[i] == rightSum[i])
                return i;
        }
                                       
        return -1;
           
    }
};