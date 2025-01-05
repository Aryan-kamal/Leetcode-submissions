class Solution {
public:
    bool function(vector<vector<char>>& board, int m, int n, string word, int i, int j, int ind) {
        if (ind == word.size()) // If the whole word is matched
            return true;

        // Boundary check and character match
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[ind])
            return false;

        char temp = board[i][j];
        board[i][j] = '$'; // Temporarily mark the cell as visited
        bool found = function(board, m, n, word, i - 1, j, ind + 1) // up
                || function(board, m, n, word, i + 1, j, ind + 1) // down
                || function(board, m, n, word, i, j - 1, ind + 1) // left
                || function(board, m, n, word, i, j + 1, ind + 1); // right
        board[i][j] = temp; // Backtrack and restore the original value of the cell in the board
        return found; // Return true if the word is found in any direction and false otherwise 
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        // search for each cell in the board -
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (function(board, m, n, word, i, j, 0))
                    return true;
            }
        }
        return false; // Return false if no match is found
    }
};