class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0; 
        string ans;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
                count++;
            else
                count--;
            
            if(((count == 1) && (s[i] == '(')) || ((count == 0) && (s[i] == ')')))
                continue;
            else
                ans += s[i];            
        }
        
        return ans;
    }
};