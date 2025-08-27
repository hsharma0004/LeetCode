class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> arr(n, vector<int>(n));
        int cnt = 1;
        int total = n * n;
        int starting_row = 0;
        int starting_col = 0;
        int ending_row = n - 1;
        int ending_col = n - 1;

        while (cnt <= total) {
            // starting Row
            for (int i = starting_col; i <= ending_col; i++) {
                arr[starting_row][i] = cnt;
                cnt++;
            }
            starting_row++;
            for (int i = starting_row; i <= ending_row; i++) {
                arr[i][ending_row] = cnt;
                cnt++;
            }
            ending_col--;
            for (int i = ending_col; i >= starting_col; i--) {
                arr[ending_row][i] = cnt;
                cnt++;
            }
            ending_row--;
            for (int i = ending_row; i >= starting_row; i--) {
                arr[i][starting_col] = cnt;
                cnt++;
            }
            starting_col++;
        }
        return arr;
    }
};