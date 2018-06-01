/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



 // recursive
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(res, root);
        return res;
    }
    
    void inorder(vector<int>& res, TreeNode* root) {
        if(root == NULL)
            return;
        inorder(res, root->left);
        res.push_back(root->val);
        inorder(res, root->right);
    }
};

//stack

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;

        stack<TreeNode*> st;

        while(root != NULL || !st.empty()) {
            while(root!= NULL) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            res.push_back(root->val);
            root = root->right;
                
        }
        return res;
    }

};


//Morris

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        TreeNode* curr = root;
        
        while(curr != NULL) {
            if(curr->left == NULL) {
                res.push_back(curr->val);
                curr = curr->right;
                continue;
            }
            TreeNode* rightmost = curr->left;
            while(rightmost->right != NULL) {
                rightmost = rightmost->right;
            }
            rightmost->right = curr;
            curr = curr->left;
            rightmost->right->left = NULL;
        }
        
        while(curr != NULL) {
            res.push_back(curr->val);
            curr = curr->right;
        }
        
        return res;
    }

};