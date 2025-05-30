/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base 
        if(root == NULL) return NULL;
        if(root->val == p->val || root->val == q->val) return root;

        TreeNode* left_ans =  lowestCommonAncestor(root->left , p , q); 
        TreeNode* right_ans = lowestCommonAncestor(root->right , p , q);

        if(left_ans != NULL && right_ans != NULL) return root; 
        else if(left_ans == NULL && right_ans != NULL) return right_ans;
        else if(left_ans != NULL && right_ans == NULL) return left_ans;
        else return NULL;
    }
};