class Solution {
public:
    int longestSubarray(vector<int>& arr) {
        int mx = *max_element(arr.begin(), arr.end());
        int mxLen = 0, curr = 0;

        for (int num : arr) {
            if (num == mx) {
                curr++;
                mxLen = max(mxLen, curr);
            } else {
                curr = 0;
            }
        }
        return mxLen;
    }
};