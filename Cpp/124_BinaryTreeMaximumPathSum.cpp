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
    int maxSum = INT_MIN;
    int maxPath(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left = maxPath(root->left);
        int right = maxPath(root->right);
        if(left < 0)
            left = 0;
        if(right < 0)
            right = 0;
        maxSum = max(maxSum, root->val+right+left );N˜
        return max(root->val+left, root->val+right);
    }
    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return maxSum;
    }
};