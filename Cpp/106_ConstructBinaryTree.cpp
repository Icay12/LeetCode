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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return recFind(inorder, postorder, (int)postorder.size()-1, 0, (int)inorder.size()-1);
    }
    TreeNode* recFind(vector<int>& inorder, vector<int>& postorder, int postindex, int inbegin, int inend) {
        if(postindex < 0 || inbegin > inend) {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postindex]);
        int inrightbegin, inleftend;
        for(int i = 0; i < inorder.size(); ++i) {
            if(inorder[i] == postorder[postindex]) {
                inrightbegin = i + 1;
                inleftend = i - 1;
                break;
            }
        }
        root->right = recFind(inorder,postorder, postindex-1, inrightbegin,inend);
        root->left = recFind(inorder,postorder, postindex - inend + inleftend, inbegin, inleftend);
        return root;
    }
};