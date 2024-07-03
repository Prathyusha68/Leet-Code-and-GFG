class Solution {
    
    bool static sortByEnd(vector<int> a, vector<int> b)
    {
        return (a[1] < b[1]);
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), sortByEnd);
        
        int end = intervals[0][1], cnt = 0;
        
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] >= end)
            {
                end = intervals[i][1];
            }
            else
            {
                cnt++;
            }
                    
        }
        
        return cnt;
    }
};