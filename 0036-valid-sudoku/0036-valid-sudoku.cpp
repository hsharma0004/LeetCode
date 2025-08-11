class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& arr) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> row, col;
            for (int j = 0; j < 9; j++) {
                if (arr[i][j] != '.') {
                    if (row.count(arr[i][j]))
                        return false;
                    row.insert(arr[i][j]);
                }
                if (arr[j][i] != '.') {
                    if (col.count(arr[j][i]))
                        return false;
                    col.insert(arr[j][i]);
                }
            }
        }
        // Check 3x3 subgrids
        for (int Row = 0; Row < 9; Row += 3) {
            for (int Col = 0; Col < 9; Col += 3) {
                unordered_set<char> boxSet;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char val = arr[Row + i][Col + j];
                        if (val != '.') {
                            if (boxSet.count(val))
                                return false;
                            boxSet.insert(val);
                        }
                    }
                }
            }
        }
        return true;
    }
};