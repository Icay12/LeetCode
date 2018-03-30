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
    bool isBalanced(TreeNode* root) {
        if(depth(root) == -1)
            return false;
        return true;
        
    }
    
    int depth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left = depth(root->left);
        if(left == -1)
            return -1;
        int right = depth(root->right);
        if(right == -1)
            return -1;
        
        if(abs(right-left) > 1 )
            return -1;
        
        return max(right, left) + 1;
        
    }
};