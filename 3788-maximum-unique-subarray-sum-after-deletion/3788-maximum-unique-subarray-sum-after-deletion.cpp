class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<int> s;
        for (int x : nums) {
            s.insert(x);
        }
        int sum = 0;
        if (nums[n - 1] < 0)
            return nums[n - 1];
        else {
            for (int i : s) {
                if (i >= 0)
                    sum += i;
            }
        }
        return sum;
    }
};