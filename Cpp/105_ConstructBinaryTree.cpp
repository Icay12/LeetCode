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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return recurFind(preorder, inorder, 0, 0, inorder.size()-1);
        
    }
    
    TreeNode* recurFind(vector<int>& preorder, vector<int>& inorder, int prebegin, int inbegin, int inend) {
        if(prebegin >= preorder.size() || inbegin > inend)
            return NULL;
        TreeNode* root = new TreeNode(preorder[prebegin]);
        int leftend;
        int rightbegin;
        int i;
        for(i = inbegin; i <= inend; ++i) {
            if(inorder[i] == preorder[prebegin]) {
                leftend = i-1;
                rightbegin = i+1;
                break;
            }
        }
        // cout << prebegin+rightbegin-inbegin << endl;
        root->left = recurFind(preorder,inorder,prebegin+1,inbegin,leftend);
        root->right = recurFind(preorder,inorder,prebegin+rightbegin-inbegin,rightbegin,inend);
        return root;
    }
};