class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> mergeVec;
        int firstVal = intervals[0][0], secVal = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++)
        {
             if(secVal >= intervals[i][0])
	         {
	             if(secVal <= intervals[i][1])
		         {
		             secVal = intervals[i][1];
		         }
	         }
	         else
	         {
	             mergeVec.push_back({firstVal,secVal});
		         firstVal = intervals[i][0];
		         secVal = intervals[i][1];
	         }
         }
 
         mergeVec.push_back({firstVal,secVal});
        
        return mergeVec;
    }
};