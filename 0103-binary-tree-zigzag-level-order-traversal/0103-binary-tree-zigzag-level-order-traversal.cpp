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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    // Iterative approach of level order traversal
       // base case
       vector<vector<int>> res;
       if(root == NULL) return res;
       queue<TreeNode*> q;
       bool direction = true; // l - R
       q.push(root);
       while(!q.empty()){
           int size = q.size();
           vector<int> ans(size,0);
           for(int i = 0 ; i < size ; i++){
               TreeNode* frontNode = q.front();
               q.pop();
               int index = direction ? i : size-i-1;
               ans[index] = frontNode->val;
               if(frontNode->left) q.push(frontNode->left);
               if(frontNode->right) q.push(frontNode->right);
           }
           direction = !direction;
            res.push_back(ans);
       }
       return res;  
    }
};