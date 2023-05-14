class Solution {
private:
    bool isValid(int adjRow, int adjCol, int n, int m)
    {
        return (adjRow >= 0 && adjRow < n && adjCol >= 0 && adjCol < m);
    }
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // <time, <row, col>>
        queue<pair<int, pair<int, int>>> que;
        vector<vector<int>> vist(n,(vector<int>(m, 0)));
        int cntFresh = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    vist[i][j] = 2;
                    que.push({0, {i, j}});
                }

                if(grid[i][j] == 1)
                    cntFresh++;
            }
        }
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        int maxTime = 0;
        while(!que.empty())
        {
            int row = que.front().second.first;
            int col = que.front().second.second;
            int time = que.front().first;
            que.pop();
            
            maxTime = max(maxTime, time);

            for(int i = 0; i < 4; i++)
            {
                int adjRow = row + dr[i];
                int adjCol = col + dc[i];
                
                if(isValid(adjRow, adjCol, n, m) && (vist[adjRow][adjCol] == 0)
                   && (grid[adjRow][adjCol] == 1))
                {
                    vist[adjRow][adjCol] = 2;
                    que.push({time+1, {adjRow, adjCol}});
                    cntFresh--;
                }
            }     
        }
        
        if(cntFresh == 0) return maxTime;
        
        return -1; 
        
    }
};