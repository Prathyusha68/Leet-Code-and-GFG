class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> mergeVec;
        mergeVec.push_back(intervals[0]);
        
        for(int i = 1; i < intervals.size(); i++)
        {
            if(mergeVec.back()[1] >= intervals[i][0])
                mergeVec.back()[1] = max (mergeVec.back()[1], intervals[i][1]);
            else
                mergeVec.push_back(intervals[i]);
        }
        
        return mergeVec;
    }
};