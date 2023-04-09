class Solution {
    
    bool isValid(vector<vector<int>> grid, int r, int c)
    {
        int m = grid.size();
        int n = grid[0].size();
        return ((r >= 0) && (r < m) && (c >= 0) && (c < n));
    }
    void bfs(vector<vector<int>>& grid, int r, int c, int newColor, int initColor, vector<vector<int>> &visited)
    {
        queue<pair<int, int>> q;
        q.push({r,c});
        grid[r][c] = newColor;
        visited[r][c] = 1;
        int di[] = {-1, 0, 1, 0};
        int dj[] = {0, 1, 0, -1};
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            //cout<<"pop..."<<row<<" "<<col<<endl;
            for(int i = 0; i < 4; i++)
            {
                int newRow = row + di[i];
                int newCol = col + dj[i];
                //cout<<newRow<<" "<<newCol<<endl;
                if(isValid(grid, newRow, newCol) && (grid[newRow][newCol] == initColor) && !visited[newRow][newCol])
                {
                    //cout<<"queuing..."<<newRow<<" "<<newCol<<endl;
                    grid[newRow][newCol] = newColor;
                    q.push({newRow, newCol});
                    visited[newRow][newCol] = 1;
                }
            }
        }
    }
    
    void dfs(vector<vector<int>>& grid, int r, int c, int newColor, int initColor, vector<vector<int>> &visited)
    {        
        grid[r][c] = newColor;
        visited[r][c] = 1;
        int di[] = {-1, 0, 1, 0};
        int dj[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++)
        {
             int newRow = r + di[i];
             int newCol = c + dj[i];
             if(isValid(grid, newRow, newCol) && (grid[newRow][newCol] == initColor) && !visited[newRow][newCol])
             {
                  dfs(grid, newRow, newCol, newColor, initColor, visited);
             }
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> visited(image.size(), vector<int>(image[0].size(), 0));
        dfs(image, sr, sc, color, image[sr][sc], visited);
        return image;
        
    }
};