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
 void findPos(vector<int> &inorder , unordered_map<int,int> &mp){
        for(int i = 0; i < inorder.size() ; i++){
            mp[inorder[i]] = i;
        }
    }
    TreeNode* solve(vector<int> &inorder, vector<int> &preorder , int &index , int in_start , int in_end , int n ,unordered_map<int,int> &mp){
        // base case
        if(index >= n || in_start > in_end) return NULL;
        
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int pos = mp[element];
        
        root->left = solve(inorder , preorder , index , in_start , pos-1, n , mp);
        root->right = solve(inorder , preorder , index , pos+1 , in_end, n , mp);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int preOrderIndex = 0;
        unordered_map<int,int> mp;
        findPos(inorder , mp);
        TreeNode* ans = solve(inorder , preorder , preOrderIndex , 0 , n-1, n , mp);
        return ans;
    }
};