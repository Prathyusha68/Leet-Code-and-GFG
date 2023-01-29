class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        
        for(int i = 0; i < n; i++)
            board[i] = s;
        
        // hash maps of left row, lower diagonal and upper diagonal
        vector<bool> leftRow(n, false), lowDiagonal(2*n-1, false), upDiagonal(2*n-1, false);
        
        solve(0, board, leftRow, lowDiagonal, upDiagonal, n, ans);
        
        return ans;
    }
    
    void solve(int col, vector<string>& board, vector<bool>& leftRow,
               vector<bool>& lowDiagonal, vector<bool>& upDiagonal, int n,
               vector<vector<string>>& ans)
    {
        if(col == n)
        {
            ans.push_back(board); //add final board result to ans
            return;
        }
        
        for(int row = 0; row < n; row++)
        {
            // check if Queen can be placed at (row, col)
            if((leftRow[row] == false) && (lowDiagonal[row+col] == false) &&
                (upDiagonal[(n-1)+(row-col)] == false))
            {
                // set Queen in (row, col) and hashmaps of leftRow, upper Diagonal, lower diagonal
                board[row][col] = 'Q';
                leftRow[row] = true;
                lowDiagonal[row+col] = true;
                upDiagonal[(n-1)+(row-col)] = true;

                solve(col+1, board, leftRow, lowDiagonal, upDiagonal, n, ans);

                // reset Queen in (row, col) and hashmaps of leftRow, upper Diagonal, lower diagonal
                board[row][col] = '.';
                leftRow[row] = false;
                lowDiagonal[row+col] = false;
                upDiagonal[(n-1)+(row-col)] = false;
            }
        }
    }
};