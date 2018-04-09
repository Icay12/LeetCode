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
    int rob(TreeNode* root) {
        int l = 0;
        int r = 0;
        int ro = irob(root, l, r);
        return ro;
    }
    int irob(TreeNode* root, int& l, int& r) {
        if(root == NULL)
            return 0;
        int ll = 0;
        int lr = 0;
        int rl = 0;
        int rr = 0;
        l = irob(root->left, ll, lr);
        r = irob(root->right, rl, rr);
        return max(root->val + ll + lr + rl + rr, l + r);
        
    }
    
    // 4-1-1-3
    
};