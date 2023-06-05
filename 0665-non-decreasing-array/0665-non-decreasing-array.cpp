class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i] > nums[i+1])
            {
                if(++cnt > 1)
                    return false;
                
                // check case "5, 7, 1"
                // if prev elem > next elem we can't change curr elem
                // So, we need to curr elem as next elem
                if((i-1 >= 0) && (nums[i-1] > nums[i+1]))
                    nums[i+1] = nums[i];
                else
                {
                    // check case "7, 1, 8"
                    // if next elem is greater than prev elem 
                    // we need to take curr elem as next elem
                    nums[i] = nums[i+1];
                }
            }
        }
        
        return true;
            
    }
};