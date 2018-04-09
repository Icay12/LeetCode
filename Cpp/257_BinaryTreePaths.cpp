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
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = "";
        vector<string> res;
        if(root == NULL)
            return res;
        visitTree(root, path, res);
        return res;
    }
    
    void visitTree(TreeNode* root, string prePath, vector<string>& res) {
        if(prePath != "")
            prePath += "->";
        prePath += to_string(root->val);
        if(root->left == NULL && root->right == NULL) {
            res.push_back(prePath);
            return;
        } 
        if(root->left != NULL)
            visitTree(root->left, prePath, res);
        if(root->right != NULL)
            visitTree(root->right, prePath, res);
        return;
    }
};