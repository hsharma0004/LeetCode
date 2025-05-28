class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        map<int, map<int, multiset<int>>> M;

        while(!q.empty()) {
            auto front = q.front(); q.pop();
            M[front.second.second][front.second.first].insert(front.first->val);

            if (front.first->left)
                q.push({front.first->left, {front.second.first + 1, front.second.second - 1}});
            if (front.first->right)
                q.push({front.first->right, {front.second.first + 1, front.second.second + 1}});
        }

        for (auto it1 : M) {
            int col = it1.first;
            auto innerMap = it1.second;

            vector<int> temp;
            for (auto it2 : innerMap) {
                for (auto it3 : it2.second)
                    temp.push_back(it3);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};