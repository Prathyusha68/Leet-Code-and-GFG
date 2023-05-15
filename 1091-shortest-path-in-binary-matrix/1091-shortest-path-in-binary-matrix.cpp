class Solution {
private:
    bool isValid(int adjRow, int adjCol, int n, int m)
    {
        return (adjRow >= 0 && adjRow < n && adjCol >= 0 && adjCol < m);
    }
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        // <dist, <row, col>>
        queue<pair<int, pair<int, int>>> q;
        
        if(grid[0][0] != 0)
            return -1;
        
        q.push({1, {0, 0}});
        dist[0][0] = 1;
        
        int dr[] = {-1, 0, 1, 0, -1, -1, 1, 1};
        int dc[] = {0, 1, 0, -1, -1, 1, 1, -1};
        while(!q.empty())
        {
            int distance = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            

            for(int i = 0; i < 8; i++)
            {
                int adjRow = row + dr[i];
                int adjCol = col + dc[i];

                if(isValid(adjRow, adjCol, n, m) && (grid[adjRow][adjCol] == 0)
                   && (distance+1 < dist[adjRow][adjCol]))
                {
                    q.push({distance+1, {adjRow, adjCol}});
                    dist[adjRow][adjCol] = distance+1;
                    cout<<adjRow<<" "<<adjCol<<" "<<dist[adjRow][adjCol]<<endl;
                }
            }            
        }
        
        if(dist[n-1][m-1] == 1e9) return -1;
        
        return dist[n-1][m-1];
    }
};