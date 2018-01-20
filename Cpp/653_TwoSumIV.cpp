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
    bool findTarget(TreeNode* root, int k) {
        set<int> hashSet;
        return find(root, k, hashSet);
    }
    bool find(TreeNode* root, int k, set<int>& hashSet) {
        if(root == NULL)
            return false;
        if(hashSet.find(k-root->val) != hashSet.end()) 
            return true;
        else
            hashSet.insert(root->val);
        
        return find(root->left,k,hashSet) || find(root->right,k,hashSet);
    }
};