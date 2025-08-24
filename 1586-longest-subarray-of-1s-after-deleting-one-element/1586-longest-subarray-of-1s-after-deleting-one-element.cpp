class Solution {
public:
    int longestSubarray(vector<int>& nums) {
    int left = 0, zero = 0, mx = 0;

    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] == 0) zero++;

        while (zero > 1) {
            if (nums[left] == 0) zero--;
            left++;
        }

        mx = max(mx, right - left);
    }
    return mx;
}

};