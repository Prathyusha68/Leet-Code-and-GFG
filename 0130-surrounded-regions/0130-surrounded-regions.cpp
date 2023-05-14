class Solution {
private:
    bool isValid(int adjRow, int adjCol, int n, int m)
    {
        return (adjRow >= 0 && adjRow < n && adjCol >= 0 && adjCol < m);
    }
    
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> q;
        int vist[n][m];
        memset(vist, 0, sizeof(vist));
        
        for(int i=0; i < n; i++)
        {
            if(board[i][0] == 'O')
            {
                q.push({i, 0});
                vist[i][0] = 1;
            }
            
            if(board[i][m-1] == 'O')
            {
                q.push({i, m-1});
                vist[i][m-1] = 1;
            }
        }
        
        for(int i=0; i < m; i++)
        {
            if(board[0][i] == 'O')
            {
                q.push({0, i});
                vist[0][i] = 1;
            }
            
            if(board[n-1][i] == 'O')
            {
                q.push({n-1, i});
                vist[n-1][i] = 1;
            }
        }
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int adjRow = row + dr[i];
                int adjCol = col + dc[i];
                if(isValid(adjRow, adjCol, n, m) && (vist[adjRow][adjCol] == 0)
                   && (board[adjRow][adjCol] == 'O'))
                {
                    q.push({adjRow, adjCol});
                    vist[adjRow][adjCol] = 1;
                }
            }            
        }
        
        for(int i=0; i < n; i++)
        {
            for(int j=0; j < m; j++)
            {
                if((board[i][j] == 'O') && (vist[i][j] == 1))
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
};