class Solution {
public:
vector<int> twoSum(vector<int>& arr, int target) {
 unordered_map<int, int> seen; 
    vector<int> ans(2, -1);

    for (int i = 0; i < arr.size(); i++) {
        int com = target - arr[i];
        if (seen.find(com) != seen.end()) {
            ans[0] = seen[com]; 
            ans[1] = i;       
            return ans;
        }
        seen[arr[i]] = i;
    }
    return ans; 
    }
};