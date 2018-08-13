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
    unordered_map<string, vector<TreeNode*>> treeString;
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        serialize(root);
        for(auto p : treeString) {
            if(p.second.size() >= 2) {
                res.push_back(p.second[0]);
            }
        }
        return res;
    }
    
    string serialize(TreeNode* root) {
        if(root == NULL)
            return "";
        string res = "(" + serialize(root->left) + to_string(root->val) + serialize(root->right) + ")";
        // cout << res << endl;
        treeString[res].push_back(root);
        return res;
    }
};