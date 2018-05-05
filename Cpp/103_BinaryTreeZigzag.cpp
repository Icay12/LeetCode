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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        queue<TreeNode*> q;
        int flag = 0; // check the level is odd/even
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> level;
            for(int i = 0; i < n; ++i) {
                level.push_back(q.front()->val);
                
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            if(flag%2) {
                reverse(level.begin(), level.end());
            }
            flag += 1;
            res.push_back(level);
        }
        return res;
    }
};