class Solution {
public:
    void function(int n,int &ans,vector<string>&tempBoard,int j,vector<int>&straight,vector<int>&lowerDiag,vector<int>&upperDiag){
            if(j==n)
            {   
                ans+=1;
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
        int totalNQueens(int n) {
            int ans=0;
            string dotString(n, '.');
            vector<string> tempBoard(n, dotString); //fill the tempBoard with dots
            vector<int>straight(n,0);
            vector<int>lowerDiag(2*n-1,0);
            vector<int>upperDiag(2*n-1,0);
            function(n,ans,tempBoard,0,straight,lowerDiag,upperDiag);
            return ans;
        }
};