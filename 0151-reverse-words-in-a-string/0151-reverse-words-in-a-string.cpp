class Solution {
public:
    string reverseWords(string s) {
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
                    //cout<<i<<" push :"<<temp<<endl;
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
            //if(st.size() > 1)
              //  ans += " ";
            st.pop();
        }
        
        return ans;
    }
};