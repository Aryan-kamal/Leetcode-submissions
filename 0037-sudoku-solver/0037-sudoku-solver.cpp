class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(isValid(board,i,j,ch)){
                            board[i][j]=ch;
                            if(solve(board)==true)
                                return true;
                            else
                                board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        // varibles useful for the 3x3 sub-grid
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        // Iterate over row, column, and sub-grid at the same time
        for (int i = 0; i < 9; i++) {
            // Check the row and column
            if (board[row][i] == ch || board[i][col] == ch)
                return false;

            // Check the 3x3 sub-grid
            int r = startRow + i / 3;
            int c = startCol + i % 3;
            if (board[r][c] == ch)
                return false;
        }
        return true;
    }
};