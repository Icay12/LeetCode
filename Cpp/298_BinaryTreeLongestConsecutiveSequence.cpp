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
    int longestConsecutive(TreeNode* root) {
        if(root == NULL)
            return 0;
        int max_path = 1;
        longest(root, max_path);
        return max_path;
    }
    int longest(TreeNode* root, int &max_path) {
        if(root == NULL)
            return 0;
        int left = longest(root->left, max_path);
        int right = longest(root->right, max_path);
        int res = 1;
        if(root->left != NULL && root->val + 1 == root->left->val) {
            left++;
            res = max(left,res);
        }
        if(root->right != NULL && root->val + 1 == root->right->val) {
            right++;
            res = max(right,res);
        }
        max_path = max(max_path,left);
        max_path = max(max_path,right);
     
        return res;
        
    }
};

