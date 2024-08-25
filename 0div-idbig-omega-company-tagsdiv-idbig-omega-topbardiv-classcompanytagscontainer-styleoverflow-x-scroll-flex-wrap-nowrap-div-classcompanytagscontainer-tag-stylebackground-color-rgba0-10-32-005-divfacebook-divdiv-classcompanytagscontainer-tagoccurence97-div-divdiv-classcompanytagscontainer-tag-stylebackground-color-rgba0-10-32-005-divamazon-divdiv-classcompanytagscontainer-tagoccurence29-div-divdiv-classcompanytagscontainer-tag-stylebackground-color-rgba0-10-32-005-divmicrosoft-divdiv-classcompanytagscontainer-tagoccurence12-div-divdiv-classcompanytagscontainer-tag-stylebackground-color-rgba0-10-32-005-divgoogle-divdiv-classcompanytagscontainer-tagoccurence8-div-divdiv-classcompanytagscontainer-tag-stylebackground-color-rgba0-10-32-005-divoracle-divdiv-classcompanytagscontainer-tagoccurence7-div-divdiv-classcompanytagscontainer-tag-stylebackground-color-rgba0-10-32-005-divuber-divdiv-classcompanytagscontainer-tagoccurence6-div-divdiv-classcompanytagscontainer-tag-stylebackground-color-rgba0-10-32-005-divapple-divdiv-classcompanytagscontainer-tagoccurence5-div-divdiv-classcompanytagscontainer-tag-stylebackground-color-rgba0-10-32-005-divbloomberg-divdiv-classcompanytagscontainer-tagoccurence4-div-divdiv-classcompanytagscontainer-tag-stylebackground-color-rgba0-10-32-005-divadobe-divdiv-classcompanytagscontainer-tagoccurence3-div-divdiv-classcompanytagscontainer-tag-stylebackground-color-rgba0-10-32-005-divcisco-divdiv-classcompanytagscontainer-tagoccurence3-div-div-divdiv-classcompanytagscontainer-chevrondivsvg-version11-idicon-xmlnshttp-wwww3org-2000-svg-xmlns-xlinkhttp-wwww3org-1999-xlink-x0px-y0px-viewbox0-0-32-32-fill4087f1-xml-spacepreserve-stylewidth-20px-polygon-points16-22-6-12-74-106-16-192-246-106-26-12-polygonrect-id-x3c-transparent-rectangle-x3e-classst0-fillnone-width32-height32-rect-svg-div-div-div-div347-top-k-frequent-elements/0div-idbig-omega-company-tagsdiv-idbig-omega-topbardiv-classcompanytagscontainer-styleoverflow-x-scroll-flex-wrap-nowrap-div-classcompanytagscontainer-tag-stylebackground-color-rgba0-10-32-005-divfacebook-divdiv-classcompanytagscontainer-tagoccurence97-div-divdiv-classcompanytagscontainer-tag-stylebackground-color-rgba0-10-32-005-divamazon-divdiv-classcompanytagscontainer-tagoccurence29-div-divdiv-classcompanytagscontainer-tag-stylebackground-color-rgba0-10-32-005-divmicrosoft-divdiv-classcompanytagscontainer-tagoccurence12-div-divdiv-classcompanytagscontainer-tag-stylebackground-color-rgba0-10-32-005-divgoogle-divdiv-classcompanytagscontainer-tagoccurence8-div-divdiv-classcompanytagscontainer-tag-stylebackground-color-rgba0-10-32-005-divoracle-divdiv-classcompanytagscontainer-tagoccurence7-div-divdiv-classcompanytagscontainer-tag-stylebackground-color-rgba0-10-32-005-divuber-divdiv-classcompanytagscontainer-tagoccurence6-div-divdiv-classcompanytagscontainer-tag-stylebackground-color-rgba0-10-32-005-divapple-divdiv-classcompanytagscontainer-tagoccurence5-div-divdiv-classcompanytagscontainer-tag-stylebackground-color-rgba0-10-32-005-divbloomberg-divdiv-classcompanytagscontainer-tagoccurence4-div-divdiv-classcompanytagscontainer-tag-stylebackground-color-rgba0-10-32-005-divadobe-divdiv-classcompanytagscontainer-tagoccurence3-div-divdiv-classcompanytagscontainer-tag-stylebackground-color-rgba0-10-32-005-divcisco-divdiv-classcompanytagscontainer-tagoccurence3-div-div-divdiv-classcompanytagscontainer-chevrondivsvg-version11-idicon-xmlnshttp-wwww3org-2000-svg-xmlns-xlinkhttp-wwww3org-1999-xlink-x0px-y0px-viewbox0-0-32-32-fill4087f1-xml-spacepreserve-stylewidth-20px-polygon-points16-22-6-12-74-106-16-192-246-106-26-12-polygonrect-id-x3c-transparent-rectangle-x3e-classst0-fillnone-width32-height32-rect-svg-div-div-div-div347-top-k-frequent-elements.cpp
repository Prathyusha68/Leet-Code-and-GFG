class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minH;
        
        for(auto it : mp)
        {
            minH.push({it.second, it.first});
            if(minH.size() > k)
                minH.pop();
        }
        
        vector<int> ans;
        
        while(minH.size())
        {
            ans.push_back(minH.top().second);
            minH.pop();
        }
        
        return ans;
    }
};