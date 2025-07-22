class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int left = 0;
        int sum = 0;
        int mx = 0;
        for (int r = 0; r < nums.size(); r++) {
            while (seen.find(nums[r]) != seen.end()) {
                sum-=nums[left];
                seen.erase(nums[left]);
                left++;  
            }
            sum+=nums[r];
            seen.insert(nums[r]);
            mx = max(sum, mx);
        }
        return mx;
    }
};