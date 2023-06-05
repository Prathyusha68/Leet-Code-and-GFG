class Solution {
private:
    void rotateApproch1(vector<int>& nums, int k, int n)
    {
        k = k%n;
        
        vector<int> temp(k, 0);
        
        for(int i = n-k; i < n; i++)
            temp[i-n+k] = nums[i];
        
        for(int i = n-k-1; i >= 0; i--)
            nums[i+k] = nums[i];
        
        for(int i = 0; i < k; i++)
            nums[i] = temp[i];
        
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
       rotateApproch1(nums, k, n);
        
    }
};