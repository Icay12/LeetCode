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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return rec(root->left, root->right);
    }
    bool rec(TreeNode* left, TreeNode* right) {
        if(left == NULL || right == NULL)
            return left == right;
        if(left->val != right->val)
            return false;
        return rec(left->left, right->right) && rec(left->right, right->left);
    }
};