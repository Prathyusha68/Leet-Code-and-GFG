class Solution {
public:
    bool checkValidString(string s) {
        int min = 0, max = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s.substr(i, 1) == "(")
            {
                min++;
                max++;
            }
            else if(s.substr(i, 1) == ")")
            {
                min--;
                max--;
            }
            else
            {
                min--;
                max++;
            }
            
            if(min < 0)
                min = 0;
            
            if(max < 0)
            {
               cout<<"return false"<<endl;
                return false;
            }
        }
        
        cout<<min<<" "<<max<<endl;
        return (min == 0);
    }
};