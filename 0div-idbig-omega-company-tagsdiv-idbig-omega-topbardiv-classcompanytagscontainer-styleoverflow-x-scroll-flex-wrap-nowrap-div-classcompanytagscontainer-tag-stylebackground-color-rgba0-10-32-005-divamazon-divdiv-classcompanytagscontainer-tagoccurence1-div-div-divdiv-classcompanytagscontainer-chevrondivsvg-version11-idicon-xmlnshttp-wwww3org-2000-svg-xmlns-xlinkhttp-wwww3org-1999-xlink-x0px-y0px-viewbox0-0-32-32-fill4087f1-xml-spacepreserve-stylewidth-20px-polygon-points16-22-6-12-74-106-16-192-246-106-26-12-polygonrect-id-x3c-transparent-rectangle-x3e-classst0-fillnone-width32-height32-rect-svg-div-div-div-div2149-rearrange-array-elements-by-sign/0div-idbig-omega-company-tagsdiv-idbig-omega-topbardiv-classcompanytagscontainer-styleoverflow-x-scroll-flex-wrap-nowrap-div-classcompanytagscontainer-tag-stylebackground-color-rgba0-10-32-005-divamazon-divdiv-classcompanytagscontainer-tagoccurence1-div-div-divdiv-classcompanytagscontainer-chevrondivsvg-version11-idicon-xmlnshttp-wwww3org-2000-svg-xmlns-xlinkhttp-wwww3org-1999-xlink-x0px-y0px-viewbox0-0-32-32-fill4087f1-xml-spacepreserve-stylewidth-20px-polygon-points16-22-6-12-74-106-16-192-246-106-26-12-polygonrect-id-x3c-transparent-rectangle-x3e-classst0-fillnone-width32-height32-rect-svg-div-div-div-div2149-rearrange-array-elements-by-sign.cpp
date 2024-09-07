class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int odd = 1, even =0;
        vector<int> ans(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++)
        {
            if((nums[i] >= 0) && (even < nums.size()))
            {
                ans[even] = nums[i];
                even += 2;
            }
            else if(odd < nums.size())
            {
                ans[odd] = nums[i];
                odd += 2;
            }
        }
        
        return ans;
    }
};