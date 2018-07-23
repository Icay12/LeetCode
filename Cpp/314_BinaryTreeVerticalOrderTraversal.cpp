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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        
        unordered_map<TreeNode*, int> hash;
        
        getRange(minimum, maximum, root, 0, hash);
        
        
        if(root == NULL)
            return vector<vector<int>>(0);
        vector<vector<int>> res(maximum-minimum+1);

        queue<TreeNode*> tovisit;
        tovisit.push(root);
        
        while(tovisit.size() != 0) {
            int n = tovisit.size();
            for(int i = 0; i < n; ++i) {
                TreeNode* cur = tovisit.front();
                tovisit.pop();
                res[hash[cur]-minimum].push_back(cur->val);
                if(cur->left != NULL) {
                    tovisit.push(cur->left);
                }
                if(cur->right != NULL)
                    tovisit.push(cur->right);
            }
        }
        
        return res;
        
    }
    
    void getRange(int& minimum, int& maximum, TreeNode* root, int position, unordered_map<TreeNode*, int> &hash) {
        if(root == NULL)
            return;
        hash[root] = position;
        // cout<< root->val << " " << position << endl;
        minimum = min(minimum, position);
        maximum = max(maximum, position);
        getRange(minimum, maximum, root->left, position-1, hash);
        getRange(minimum, maximum, root->right, position+1, hash);
    }
};