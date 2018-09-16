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
    int res = INT_MAX;
    int pre = 0;
    bool first = true;
public:
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return res;
    }
    
    void inorder(TreeNode* root) {
        if(root == NULL)
            return;
        if(root->left == NULL && first) {
            first = false;
        }
        else {
            inorder(root->left);
            res = min(res, (root->val - pre));
        }

        pre = root->val;
        inorder(root->right);
    }
};