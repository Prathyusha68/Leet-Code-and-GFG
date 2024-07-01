class Solution {
public:
    int jump(vector<int>& nums) {
        int l =0, r =0;
        int cnt =0;
        
        while(r < nums.size()-1)
        {
            int fartest = 0;
            for(int i = l; i <= r; i++)
            {
                fartest = max(fartest, i + nums[i]);
            }
            l = r+1;
            r = fartest;
            cnt += 1;
        }
        
        return cnt;
    }
};