class Solution {
public:
bool canFormPairs(vector<int>& nums, int maxDiff, int p) {
    int count = 0;
    int i = 1;
    while (i < nums.size()) {
        if (nums[i] - nums[i - 1] <= maxDiff) {
            count++;
            i += 2; 
        } else {
            i++;
        }
    }
    return count >= p;
}
    int minimizeMax(vector<int>& nums, int p) {
        // maximum of minimum difference 
         sort(nums.begin(), nums.end());

    int left = 0;
    int right = nums.back() - nums.front(); // max possible diff
    int answer = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canFormPairs(nums, mid, p)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return answer;
    }
};