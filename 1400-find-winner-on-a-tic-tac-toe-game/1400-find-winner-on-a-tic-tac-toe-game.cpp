class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> grid(3, vector<int>(3, -1));
        int n = moves.size();
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                grid[moves[i][0]][moves[i][1]] = 1; // A
            else
                grid[moves[i][0]][moves[i][1]] = 0; // B
        }

        int win = -1;
        bool b = false;
        // row
        for (int i = 0; i < 3; i++) {
            if (grid[i][0] != -1 && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
                b = true;
                win = grid[i][0];
                break;
            }
        }
        // column
        for (int i = 0; i < 3; i++) {
            if (grid[0][i] != -1 && grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) {
                b = true;
                win = grid[0][i];
                break;
            }
        }
        // diagonal
        if (grid[1][1] != -1) {
            if ((grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) || 
                (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])) {
                b = true;
                win = grid[1][1];
            }
        }

        if (!b) {
            if (n == 9)
                return "Draw";
            return "Pending";
        }
        return win == 1 ? "A" : "B";
    }
};
