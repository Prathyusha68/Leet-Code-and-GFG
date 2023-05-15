class Solution {
private:
    bool isValid(int adjRow, int adjCol, int n, int m)
    {
        return (adjRow >= 0 && adjRow < n && adjCol >= 0 && adjCol < m);
    }
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        // <effort, <row, col>>
        priority_queue<pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> pq;
        
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        while(!pq.empty())
        {
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            
            pq.pop();
            for(int i = 0; i < 4; i++)
            {
                int adjRow = row + dr[i];
                int adjCol = col + dc[i];
                
                if(isValid(adjRow, adjCol, n, m))
                {
                    int minEffort = max(abs(heights[row][col] - heights[adjRow][adjCol]), diff);
                    
                    if(minEffort < dist[adjRow][adjCol])
                    {
                        dist[adjRow][adjCol] = minEffort;
                        pq.push({minEffort, {adjRow, adjCol}});
                    }
                }
            }
        }
        
        return dist[n-1][m-1];
    }
};