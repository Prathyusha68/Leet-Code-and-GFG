class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;
        int n = nums2.size();
        
        for(int i = n-1; i >=0; i--)
        {
            while(!st.empty() && (nums2[st.top()] <= nums2[i]))
                st.pop();
                
            if(!st.empty())
            {
                mp[nums2[i]] = nums2[st.top()];
            }
            
            st.push(i);
        }
        
        vector<int> ans(nums1.size(), -1);
        for(int i = 0; i < nums1.size(); i++)
        {
            if(mp.find(nums1[i]) != mp.end())
            {
                ans[i] = mp[nums1[i]];
            }
        }
        
        return ans;
    }
};