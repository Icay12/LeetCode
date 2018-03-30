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
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* pre = new TreeNode(INT_MIN);
    
    void recoverTree(TreeNode* root) {
        findNodes(root);
        swap(first->val, second->val);
        

    }
    void findNodes(TreeNode* root) {
        if(root == NULL)
            return;
        
        //in order traverse
        //then the elements we see are in ascending order
        
        findNodes(root->left);
        
        //first is bigger, second is smaller
        if(first == NULL && pre->val >= root->val)
            first = pre;
        
        //here we cannot use else if, think about when there're only two elements in the tree
        if(first != NULL && pre->val >= root->val)
            second = root;
        
        pre = root;
        
        findNodes(root->right);
    }
};