class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, maxCnt =0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                cnt++;
            }
            else
            {
                maxCnt = max(maxCnt, cnt);
                cnt = 0;
            }
        }
        
        maxCnt = max(cnt, maxCnt);
        return maxCnt;
    }
};