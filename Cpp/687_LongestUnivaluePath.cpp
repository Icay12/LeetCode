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
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL)
            return 0;
        int imax = 0;
        visit(root, imax);
        return imax;
    }
    
    int visit(TreeNode* root, int &imax) {
        if(root == NULL)
            return 0;
        
        int left = visit(root->left, imax);
        int right = visit(root->right, imax);
        int rleft = 0;
        int rright = 0;

        if(root->left != NULL && root->val == root->left->val)
            rleft = left + 1;
        if(root->right != NULL && root->val == root->right->val)
            rright = right + 1;

        imax = max(imax, rleft+rright);

        return max(rleft,rright);
        
            
    }
};