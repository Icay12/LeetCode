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
    int sumNumbers(TreeNode* root) {
        return doSum(root, 0);
    }
    
    int doSum(TreeNode* root, int s) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right==NULL)
            return root->val + s*10;
        return doSum(root->left, s*10 + root->val) + doSum(root->right, s*10 + root->val);
    }
};