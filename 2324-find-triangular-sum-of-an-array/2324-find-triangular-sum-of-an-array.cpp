class Solution {
public:
    int lastdigit(int x)
    { return x % 10; }

    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        while (n > 1) {
            vector<int> temp(n - 1, 0);
            for (int i = 1; i < n; i++) {
                int sum = nums[i - 1] + nums[i];
                if ((sum) > 9)
                    temp[i - 1] = lastdigit(sum);
                else
                    temp[i - 1] = sum;
            }
            nums = temp;
            n--;
        }
        return nums[0];
    }
};