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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        if(nums.size() == 0)
            return NULL;
        TreeNode* root = new TreeNode(nums[0]);
        for(int i = 1; i < nums.size(); ++i) {
            TreeNode* num = new TreeNode(nums[i]);
            root = construct(root, num);
        }
        return root;
    }
    
    TreeNode* construct(TreeNode* root, TreeNode* num) {
        if(root == NULL) {
            return num;
        }
        if(num->val > root->val) {
            num->left = root;
            return num;
        }
        else {
            root->right = construct(root->right, num);
            return root;
        }
    }
};


//Time Complexity O(n)
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        if(nums.size() == 0)
            return NULL;
        vector<TreeNode*> stack;
        for(int i = 0; i < nums.size(); ++i) {
            TreeNode* cur = new TreeNode(nums[i]);
            while(!stack.empty() && stack.back()->val < nums[i]) {
                cur->left = stack.back();
                stack.pop_back();
            } 
            if(!stack.empty()) {
                stack.back()->right = cur;
            }
            stack.push_back(cur);
        }
        return stack.front();
    }
};