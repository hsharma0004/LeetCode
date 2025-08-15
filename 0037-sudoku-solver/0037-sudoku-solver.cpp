class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, int val) {
        char ch = val + '0';
        for (int i = 0; i < board.size(); i++) {
            // Row
            if (board[row][i] == ch) {
                return false;
            }

            // Col
            if (board[i][col] == ch) {
                return false;
            }

            // 3x3 MAtrix check
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        int n = board.size();
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] == '.') {
                    for (int val = 1; val <= 9; val++) {
                        if (isSafe(row, col, board, val)) {
                            char ch = val + '0';
                            board[row][col] = ch;
                            // recursive call
                            bool SolutionPossible = solve(board);
                            if (SolutionPossible)
                                return true;
                            else {
                                // Backtrack
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) { 
        solve(board); 
    }
};