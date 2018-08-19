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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
    
    void postorder(TreeNode* root, vector<int> &res) {
        if(!root) {
            return;
        }
        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
    }
};

// two stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> res;
        if(root == NULL)
            return res;
        
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        st1.push(root);
        
        while(!st1.empty()) {
            root = st1.top();
            st1.pop();
            st2.push(root);
            if(root->left) {
                st1.push(root->left);
            }
            if(root->right) {
                st1.push(root->right);
            }
        }
        
        while(!st2.empty()) {
            res.push_back(st2.top()->val);
            st2.pop();
        }
        return res;
    }
    
};

//one stack


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> res;
        if(root == NULL)
            return res;
        
        stack<TreeNode*> st1;
        st1.push(root);
        
        while(!st1.empty()) {
            while(root != NULL) {
                if(root->right) {
                    st1.push(root->right);
                }
                st1.push(root);
                root = root->left;
            }
            
            root = st1.top();
            st1.pop();
            if(st1.empty()) {
                break;
            }
            
            if(root->right != st1.top()) {
                res.push_back(root->val);
                root = NULL;
            }
            else {
                TreeNode* tmp = st1.top();
                st1.pop();
                st1.push(root);
                root = tmp;
            }
        }

        return res;
    }
    
};