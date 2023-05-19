class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        
        if(nums.size() == 1)
            return nums[0];
        
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            
            if((mid > 0) && (nums[mid] < nums[mid-1]))
                return nums[mid];
            
            if(nums[mid] < nums[low])
                high = mid-1;
            else if(nums[mid] > nums[high])
                low = mid+1;
            else 
                return nums[low];
        }
        
        return INT_MAX;
    }
};