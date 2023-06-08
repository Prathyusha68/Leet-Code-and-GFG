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
        
        cout<<st.size()<<endl;
        ans += st.top();
        st.pop();
        
        while(!st.empty())
        {
            ans += " "+st.top();
            st.pop();
        }
        
        return ans;
    }
public:
    string reverseWords(string s) {
        return approach1(s);
    }
};