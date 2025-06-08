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
  TreeNode* solve(vector<int> &inorder, vector<int> &postorder , int &index , int in_start , int in_end , int n ,unordered_map<int,int> &mp){
        // base case
        if(index < 0 || in_start > in_end) return NULL;
        
        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);
        int pos = mp[element];
        
        root->right = solve(inorder , postorder , index , pos+1 , in_end, n , mp);
        root->left = solve(inorder , postorder , index , in_start , pos-1, n , mp);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
     int n = inorder.size();
        int postOrderIndex = n-1;
        unordered_map<int,int> mp;
        findPos(inorder , mp);
        TreeNode* ans = solve(inorder , postorder , postOrderIndex , 0 , n-1, n , mp);
        return ans;     
    }
};