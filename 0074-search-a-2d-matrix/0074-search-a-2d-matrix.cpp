class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int start = 0, end = n*m-1;
        
        while(start <= end)
        {
            int mid = (start+end) >> 1;
            
            if(matrix[mid/m][mid%m] == target)
                return true;
            
            if(target < matrix[mid/m][mid%m])
            {
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        
        return false;
    }
};