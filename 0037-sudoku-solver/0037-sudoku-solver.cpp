class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);  
    }
    
    bool solve(vector<vector<char>>& board)
    {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == '.')
                {
                    for(char c = '1'; c <= '9'; c++)
                    {
                        if(isValid(board, i, j, c) == true)
                        {
                            board[i][j] = c; // set 'c' if its valid
                            if(solve(board) == true)
                                return true;
                            else
                                board[i][j] = '.'; // reset if this value doesn't gives desired output
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char c)
    {
        for(int i = 0; i < 9; i++)
        {
            // check if 'c' is already available in same row 
            if(board[row][i] == c)
                return false;
            // check if 'c' is already available in same column 
            if(board[i][col] == c)
                return false;
            // check if 'c' is already available in same 3X3 grid 
            if(board[(3*(row/3))+(i/3)][(3*(col/3))+(i%3)] == c)
                return false;
        }
        return true;
    }
};