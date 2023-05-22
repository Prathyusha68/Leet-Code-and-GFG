class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int, int> mp;
        
        if(s.length() == 0)
            return 0;
        
        mp[s[0]] = 0;
        int l = 0, maxLen = 1;
        for(int r = 1; r < s.length(); r++)
        {
            if(mp.find(s[r]) != mp.end()) 
            {                
                l = max(l, (mp[s[r]]+1));
            }
            
            maxLen = max(maxLen, (r-l+1));

            mp[s[r]] = r;
        }
        
        return maxLen;
    }
};