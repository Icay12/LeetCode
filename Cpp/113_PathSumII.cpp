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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> current;
        rec(root, sum, res, current);
        return res;
    }
    void rec(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& current) {
        if(root == NULL)
            return;
        current.push_back(root->val);
        if(root->left == NULL && root->right == NULL && root->val == sum) {
            res.push_back(current);
        }
        rec(root->left, sum-root->val, res, current);
        rec(root->right, sum-root->val, res, current);
        current.pop_back();
        return;
    }
};