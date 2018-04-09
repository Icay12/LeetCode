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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return arrayToBST(nums, 0, nums.size());
    }
    
    TreeNode* arrayToBST(vector<int>& nums, int head, int tail) {
        if(head == tail) {
            return NULL;
        }
        //find middle node
        int mid = (head + tail) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = arrayToBST(nums, head, mid);
        root->right = arrayToBST(nums,mid+1, tail);
        return root;
    }
};