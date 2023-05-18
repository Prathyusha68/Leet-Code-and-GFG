class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        
        // Calculate all left side multiple
        // i/p  :  1    2    3    4 
        // left :       1   1*2   1*2*3
        // right: 2*3*4 3*4  4
        // fill left 1st elem and right last elem as "1"
        // Now multiply left and right side multiples at that index
        // o/p  :  24    12   8    6
        
        int left = 1;
    
        for(int i = 0; i < n; i++)
        {
            if(i > 0)
                left = nums[i-1] * res[i-1];
            res[i] = left;
        }
        
        int right = 1;
        
        for(int i = n-1; i >= 0; i--)
        {
            if(i < n-1)
                right *= nums[i+1];
            res[i] *= right;
        }
        
        return res;
        
    }
};