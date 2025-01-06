class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        for (int j = 0; j < col; j++) // Check left row
            if (board[row][j] == 'Q') 
                return false;
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) // Check upper left diagonal
            if (board[i][j] == 'Q')
                return false;
        for (int i = row, j = col; i < n && j >= 0; i++, j--) // Check lower left diagonal
            if (board[i][j] == 'Q')
                return false;
        return true;
    }
    void function(int n,vector<vector<string>>&ans,vector<string>&tempBoard,int j){
        if(j==n)
        {   
            ans.push_back(tempBoard);
            return;
        }
        for(int x=0;x<n;x++)
        {
            if(isSafe(tempBoard,x,j,n))
            {
                tempBoard[x][j]='Q';
                function(n,ans,tempBoard,j+1);
                tempBoard[x][j]='.';
            }
        }
            
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string dotString(n, '.');
        vector<string> tempBoard(n, dotString); //fill the tempBoard with dots
        function(n,ans,tempBoard,0);
        return ans;
    }
};