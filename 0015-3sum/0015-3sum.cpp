class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n-2; i++)
        {
            if((i == 0) || ((i > 0) && (nums[i] != nums[i-1])))
            {
                int lo = i+1, hi = n-1, sum = 0-nums[i];
                
                // 2 pointer approach
                while(lo < hi)
                {
                    if(sum == nums[lo]+nums[hi])
                    {
                        res.push_back({nums[i], nums[lo], nums[hi]});
                        
                        while((lo < hi) && (nums[lo] == nums[lo+1])) lo++;
                        while((lo < hi) && (nums[hi] == nums[hi-1])) hi--;
                    }
                    
                    if(sum > nums[lo]+nums[hi])
                        lo++;
                    else
                        hi--;
                        
                }
            }
        }
        
        return res;
    }
};