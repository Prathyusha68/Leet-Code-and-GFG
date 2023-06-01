class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for(int i = 0; i < n-3; i++)
        {
            if((i > 0) && (nums[i] == nums[i-1]))
                continue;
            
            for(int j = i+1; j < n-2; j++)
            {    
                if((j > i+1) && (nums[j] == nums[j-1]))
                    continue;
                
                int lo = j+1, hi = n-1;

                // 2 pointer approach
                while(lo < hi)
                {
                    // either typecast every nums[x] value to long long or you can just declare long long sum = nums[a] and then do rest of the additions like this
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[lo];
                    sum += nums[hi];
                    //long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[lo] + (long long)nums[hi];
                                     
                    if(sum == target)
                    {
                        res.push_back({nums[i], nums[j], nums[lo], nums[hi]});
                        
                        while((lo < hi) && (nums[lo] == nums[lo+1])) lo++;
                        while((lo < hi) && (nums[hi] == nums[hi-1])) hi--;                   
                    }

                    if(sum < target)
                        lo++;
                    else
                        hi--;
                        
                }
            }

        }
        
        return res;
    }
};