class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int tmp = nums[0], i = 1;
        
        for(int j = 1; j < nums.size(); j++)
        {
            if(nums[j] != tmp)
            {
                nums[i++] = nums[j];
                tmp = nums[j];
            }
        }
        
        return i;
    }
};