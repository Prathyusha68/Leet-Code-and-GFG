//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
  
    bool isValid(int adjRow, int adjCol, int n, int m)
    {
        return (adjRow >= 0 && adjRow < n && adjCol >= 0 && adjCol < m);
    }
    
    void dfs(int i, int j, vector<vector<int>>& grid, int startRow,
        int startCol, vector<pair<int,int>> &vec, int n, int m, vector<vector<int>> &vist)
    {
        vec.push_back({i-startRow, j-startCol});
        vist[i][j] = 1;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        for(int k = 0; k < 4; k++)
        {
            int adjRow = i + dr[k];
            int adjCol = j + dc[k];
            
            if(isValid(adjRow, adjCol, n, m) && (vist[adjRow][adjCol] == 0) && (grid[adjRow][adjCol] == 1))
            {
                dfs(adjRow, adjCol, grid, startRow, startCol, vec, n, m, vist);
            }
        }
        
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vist(n, vector<int>(m, 0));
        set<vector<pair<int,int>>> st;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if((vist[i][j] == 0) && (grid[i][j] == 1))
                {
                    vector<pair<int,int>> vec;
                    dfs(i, j, grid, i, j, vec, n, m, vist);
                    st.insert(vec);
                }
            }
        }
        
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends