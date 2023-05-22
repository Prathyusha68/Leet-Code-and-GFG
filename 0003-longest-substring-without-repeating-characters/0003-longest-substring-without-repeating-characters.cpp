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
            cout<<l<<" "<<r<<endl;
            if(mp.find(s[r]) != mp.end()) 
            {                
                l = max(l, (mp[s[r]]+1));
                cout<<"enter :"<<l<<" "<<r<<" "<<maxLen<<endl;
            }
            
            maxLen = max(maxLen, (r-l+1));
            
            cout<<maxLen<<endl;
            mp[s[r]] = r;
        }
        
        return maxLen;
    }
};