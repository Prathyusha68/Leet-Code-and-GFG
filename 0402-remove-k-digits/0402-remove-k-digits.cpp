class Solution {
public:
    string removeKdigits(string nums, int k) {
        list<int> st;

        if(k >= nums.length())
          return "0";

        if(k == 0)
            return nums;

        int num = stoi(nums.substr(0, 1));
        st.push_back(num);

        for(int i = 1; i < nums.length(); i++)
        {
            num = stoi(nums.substr(i, 1));

            while((!st.empty()) && (st.back() > num) && (k > 0))
            {
                k--;
                st.pop_back();
            }

            st.push_back(num);
        }

        while((k > 0) && st.size())
        {
            k--;
            st.pop_back();
        }

        string ans = "";

        for(auto iter = st.begin(); iter != st.end(); )
        {
            if(*iter == 0)
                iter = st.erase(iter);
            else
                break;
        }

        for(auto it : st)
        {
            ans += to_string(it);
        }

        return (ans.size() == 0) ? "0" : ans;
    }
};