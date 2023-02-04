/* 
 * Possible cases :
 * ==============
 * All Negative values case : Min Val
 * Negative values + Zero   : Zero
 * All Positives            : Max +ve val
 * -ve and +ve              : Max +ve val
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_prod_end = nums[0], min_prod_end = nums[0], max_prod_overall = nums[0];
        
        for(int i = 1; i < nums.size(); i++)
        {
            // max of curr val, prod of curr val and max prod till now,
            // prod of curr val and min val till now
            int tmp = max({nums[i], max_prod_end*nums[i], min_prod_end*nums[i]});
            
            // min of curr val, prod of curr val and max prod till now,
            // prod of curr val and min val till now (for -ve val)
            min_prod_end = min({nums[i], max_prod_end*nums[i], min_prod_end*nums[i]});
            
            max_prod_end = tmp;
            
            // max of max prod till now and final max prod
            max_prod_overall = max(max_prod_overall, max_prod_end);
        }
        return max_prod_overall;
    }
};