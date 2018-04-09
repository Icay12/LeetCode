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
    TreeNode* pre = NULL;

    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
        if(!isValidBST(root->left))
            return false;
        if(pre != NULL && pre->val >= root->val)
            return false;
        pre = root;
        
        if(!isValidBST(root->right))
            return false;

        return true;
    }
    
};