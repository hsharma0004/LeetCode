/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, long long target, long long currSum, unordered_map<long long, int>& mp, int& cnt) {
    if (!root) return;

    currSum += (long long)root->val;


    if (mp.find(currSum - target) != mp.end()) {
        cnt += mp[currSum - target];
    }

    mp[currSum]++;

    dfs(root->left, target, currSum, mp, cnt);
    dfs(root->right, target, currSum, mp, cnt);

    mp[currSum]--; 
}
    int pathSum(TreeNode* root, int target) {
       unordered_map<long long, int> mp;
    mp[0] = 1; 
    int cnt = 0;
    dfs(root, (long long)target, 0LL, mp, cnt);
    return cnt;
    }
};