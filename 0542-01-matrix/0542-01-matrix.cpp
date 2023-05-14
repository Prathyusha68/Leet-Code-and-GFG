class Solution {
private:
    bool isValid(int adjRow, int adjCol, int n, int m)
    {
        return (adjRow >= 0 && adjRow < n && adjCol >= 0 && adjCol < m);
    }
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, 0));
        int vist[n][m];
        //<distance, <row, col>>
        queue<pair<int, pair<int, int>>> q;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({0, {i, j}});
                    dist[i][j] = 0;
                    vist[i][j] = 1;
                }
                else
                    vist[i][j] = 0;
            }
        }
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        while(!q.empty())
        {
            int row = q.front().second.first;
            int col = q.front().second.second;
            int distance = q.front().first;
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int adjRow = row + dr[i];
                int adjCol = col + dc[i];
                                     
                if(isValid(adjRow, adjCol, n, m) && (vist[adjRow][adjCol] == 0)
                  && (mat[adjRow][adjCol] == 1))
                {
                    q.push({distance+1, {adjRow, adjCol}});
                    dist[adjRow][adjCol] = distance+1;
                    vist[adjRow][adjCol] = 1;
                }
            }
        }
        return dist;
    }
};