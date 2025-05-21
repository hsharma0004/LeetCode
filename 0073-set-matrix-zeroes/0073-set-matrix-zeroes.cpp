class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
    vector<vector<int>> nums = arr;
    int rows = arr.size();
    int cols = arr[0].size();
    int cnt=0;
    for (int i = 0; i < rows; i++)
    {
       for (int j = 0; j < cols; j++)
       {
        if(arr[i][j] == 0) {
            for (int k = 0; k < cols; k++)
            {
                nums[i][k] =0;
            }
            for (int m = 0; m < rows; m++)
            {
                nums[m][j]=0;
            }
        }
       } 
    }
    arr = nums;    
    }
};