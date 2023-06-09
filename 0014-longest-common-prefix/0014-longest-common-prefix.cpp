class Solution {
public:
    string longestCommonPrefix(vector<string>& vec) {
        string res;
        int n = vec.size();
        
        if(n == 1)
            return vec[0];
        
        sort(vec.begin(), vec.end());
        
        string start = vec[0], end = vec[n-1];
        
        for(int i = 0; i < min(start.length(), end.length()); i++)
        {
            if(start[i] != end[i])
                return res;
            else
                res += start[i];
        }
        
        return res;
    }
};