class Solution {
    string approach1(string s) {
        stack<string> st;
        string ans;
        
        string temp;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != ' ')
            {
                while((i < s.length()) && (s[i] != ' '))
                {
                    temp += s[i];
                    i++;
                }

                st.push(temp);
                temp = "";
            }
        }
        
        ans += st.top();
        st.pop();
        
        while(!st.empty())
        {
            ans += " "+st.top();
            st.pop();
        }
        
        return ans;
    }
    
    string approach2(string s) {
        int i = 0;
        int n = s.length();
        string res;
        
        while(i < n)
        {
            while((i < n) && (s[i] == ' '))
                i++;
            
            if(i >= n)
                continue;
            
            int j = i;
            while((j < n) && (s[j] != ' '))
                j++;
            
            if(res.length() == 0)
                res = s.substr(i, j-i);
            else
                res = s.substr(i, j-i)+" "+res;
            
            i = j+1;
        }
        return res;
    }
    
public:
    string reverseWords(string s) {
        return approach2(s);
    }
};