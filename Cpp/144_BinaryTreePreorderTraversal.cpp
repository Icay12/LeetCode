/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//recursive
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
    
    void preorder(TreeNode* root, vector<int>& res) {
        if(root == NULL)
            return;
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }
    
};

//stack
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur != NULL || !st.empty()) {
            while(cur != NULL) {
                res.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            cur = cur->right;
        }
        return res;
    }
    
};


//Morris
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        
        TreeNode* cur = root;
        TreeNode* nothing = root;
        while(cur != NULL) {
            res.push_back(cur->val);
            if(cur->left == NULL) {
                cur = cur->right;
                continue;
            }
            
            TreeNode* rightmost = cur->left;
            while(rightmost->right != NULL) {
                rightmost = rightmost->right;
            }
            if(cur->right != NULL) {
                rightmost->right = cur->right;
            }

            nothing = cur;
            cur = cur->left;
            nothing->left = NULL;
            nothing->right = NULL;
        }

        return res;
    }
    
};