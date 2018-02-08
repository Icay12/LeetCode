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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> level;
        int depth = 0;
        rec(root, res, depth);
        return res;
    }
    void rec(TreeNode* root, vector<vector<int>>& res, int depth) {
        if(root == NULL)
            return;
        if(res.size() == depth) {
            res.push_back(vector<int>());
        }
        res[depth].push_back(root->val);
        rec(root->left, res, depth+1);
        rec(root->right, res, depth+1);
        
    }
};