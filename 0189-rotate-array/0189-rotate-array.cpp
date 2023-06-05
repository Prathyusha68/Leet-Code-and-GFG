class Solution {
private:
    void rotateApproch1(vector<int>& nums, int k, int n)
    {
        k = k%n;
        
        vector<int> temp(k, 0);
        
        // save last K elems in "temp" vector
        for(int i = n-k; i < n; i++)
            temp[i-n+k] = nums[i];
        
        // As last K elems are stored in "temp" vector
        // we can copy the "nums" vector from last with start elems
        // which won't impact last 'K' elems
        for(int i = n-k-1; i >= 0; i--)
            nums[i+k] = nums[i];
        
        // add last "K" elems saved in "temp" vector to "nums" vector from starting
        for(int i = 0; i < k; i++)
            nums[i] = temp[i];
        
    }
    
    void reverse(int start, int end, vector<int>& nums)
    {
        while(start < end)
        {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
    
    void rotateApproch2(vector<int>& nums, int k, int n)
    {
        k = k%n;
        
        reverse(0, n-k-1, nums);
        reverse(n-k, n-1, nums);
        reverse(0, n-1, nums);
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
       rotateApproch2(nums, k, n);
        
    }
};