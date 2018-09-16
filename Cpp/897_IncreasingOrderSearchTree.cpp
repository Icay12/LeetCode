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
    TreeNode* pre = NULL;
public:
    
    TreeNode* increasingBST(TreeNode* root) {
        if(root == NULL) {
            return NULL;
        }
        
        TreeNode* res = increasingBST(root->left);
        if(res == NULL) {
            res = root;
            pre = res;
        }
        else {
            root->left = NULL;
            pre->right = root;
            pre = root;
        }
        
        TreeNode* r = increasingBST(root->right);
        root->right = r;
        
        return res;
        
    }
};