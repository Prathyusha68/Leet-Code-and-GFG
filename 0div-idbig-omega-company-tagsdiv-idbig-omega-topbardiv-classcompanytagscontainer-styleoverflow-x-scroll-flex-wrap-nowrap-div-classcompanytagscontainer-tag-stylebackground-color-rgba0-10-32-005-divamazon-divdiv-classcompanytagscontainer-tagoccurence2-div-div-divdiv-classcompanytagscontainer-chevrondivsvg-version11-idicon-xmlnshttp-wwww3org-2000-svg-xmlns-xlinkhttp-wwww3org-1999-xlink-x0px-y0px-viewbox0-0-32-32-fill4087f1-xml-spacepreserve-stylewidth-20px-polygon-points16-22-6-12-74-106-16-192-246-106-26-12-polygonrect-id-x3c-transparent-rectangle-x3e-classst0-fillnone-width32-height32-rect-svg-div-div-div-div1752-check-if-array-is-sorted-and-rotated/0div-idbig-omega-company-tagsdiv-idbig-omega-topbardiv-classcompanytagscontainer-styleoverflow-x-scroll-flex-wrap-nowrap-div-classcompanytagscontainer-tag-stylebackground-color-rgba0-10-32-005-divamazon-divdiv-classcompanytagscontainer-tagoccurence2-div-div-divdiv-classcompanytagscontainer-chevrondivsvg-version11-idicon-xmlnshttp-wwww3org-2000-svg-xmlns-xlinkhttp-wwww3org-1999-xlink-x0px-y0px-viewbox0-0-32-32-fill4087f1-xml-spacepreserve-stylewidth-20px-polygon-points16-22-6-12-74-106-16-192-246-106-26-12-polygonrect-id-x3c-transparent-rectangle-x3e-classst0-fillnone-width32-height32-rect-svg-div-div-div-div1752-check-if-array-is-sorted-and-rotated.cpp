class Solution {
public:
    bool check(vector<int>& nums) {
        int size = nums.size();
        int count = 0;
        
        for(int i = 0; i < size; i++)
        {
            if(nums[i] > nums[(i+1)%size])
                count++;
        }
        
        // if vector is not sorted there will be more than one peak
        if(count <= 1)
            return true;
        else
            return false;
    }
};