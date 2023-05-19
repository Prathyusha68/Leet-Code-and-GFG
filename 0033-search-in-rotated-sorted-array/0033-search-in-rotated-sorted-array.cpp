class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if((n == 1 && (nums[n-1] != target)) || (n == 0))
            return -1;
        
        int start = 0, end = n-1;
        
        while(start <= end)
        {
            int mid = start+(end-start)/2;
            
            if(nums[mid] == target)
                return mid;
            
            // find which part is sorted 
            if(nums[mid] >= nums[start])
            {
                // check if 'target' is in sorted part or not
                if((nums[start] <= target) && (target <= nums[mid]))
                    end = mid-1;
                else
                    start = mid+1;
            }
            else
            {
                // check if 'target' is in sorted part or not
                if((nums[mid] <= target) && (target <= nums[end]))
                    start = mid+1;
                else
                    end = mid-1;
            }
            
        }
        
        return -1;
    }
};