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

   bool Validate(TreeNode* root , long long  min , long long  max){
    if(root == NULL) return true;
    if(root->val > min && root->val < max){
        bool left = Validate(root->left , min , root->val);
        bool right = Validate(root->right , root->val , max);
        return left && right;
    }
    else return false;
   }


    bool isValidBST(TreeNode* root) {
        long long min = -1000000000000;
        long long max = 1000000000000;
        return Validate(root , min, max);
    }
};