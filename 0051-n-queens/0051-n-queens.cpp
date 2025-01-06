class Solution {
public:
    //M-1 -
    // bool isSafe(vector<string>& board, int row, int col, int n) {
    //     for (int j = 0; j < col; j++) // Check left row
    //         if (board[row][j] == 'Q') 
    //             return false;
    //     for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) // Check upper left diagonal
    //         if (board[i][j] == 'Q')
    //             return false;
    //     for (int i = row, j = col; i < n && j >= 0; i++, j--) // Check lower left diagonal
    //         if (board[i][j] == 'Q')
    //             return false;
    //     return true;
    // }
    // void function(int n,vector<vector<string>>&ans,vector<string>&tempBoard,int j){
    //     if(j==n)
    //     {   
    //         ans.push_back(tempBoard);
    //         return;
    //     }
    //     for(int x=0;x<n;x++)
    //     {
    //         if(isSafe(tempBoard,x,j,n))
    //         {
    //             tempBoard[x][j]='Q';
    //             function(n,ans,tempBoard,j+1);
    //             tempBoard[x][j]='.';
    //         }
    //     }
            
    // }
    // vector<vector<string>> solveNQueens(int n) {
    //     vector<vector<string>>ans;
    //     string dotString(n, '.');
    //     vector<string> tempBoard(n, dotString); //fill the tempBoard with dots
    //     function(n,ans,tempBoard,0);
    //     return ans;
    // }

    // M-2 (optimised one) -
    void function(int n,vector<vector<string>>&ans,vector<string>&tempBoard,int j,vector<int>&straight,vector<int>&lowerDiag,vector<int>&upperDiag){
        if(j==n)
        {   
            ans.push_back(tempBoard);
            return;
        }
        for(int x=0;x<n;x++)
        {
            if(straight[x]!=1 && lowerDiag[x+j]!=1 && upperDiag[n-1+j-x]!=1)
            {
                tempBoard[x][j]='Q';
                straight[x]=1;
                lowerDiag[x+j]=1;
                upperDiag[n-1+j-x]=1;
                function(n,ans,tempBoard,j+1,straight,lowerDiag,upperDiag);
                tempBoard[x][j]='.';
                straight[x]=0;
                lowerDiag[x+j]=0;
                upperDiag[n-1+j-x]=0;
            }
        }
            
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string dotString(n, '.');
        vector<string> tempBoard(n, dotString); //fill the tempBoard with dots
        vector<int>straight(n,0);
        vector<int>lowerDiag(2*n-1,0);
        vector<int>upperDiag(2*n-1,0);
        function(n,ans,tempBoard,0,straight,lowerDiag,upperDiag);
        return ans;
    }
};