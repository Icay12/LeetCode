/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//DFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int minLeft = minDepth(root->left);
        int minRight = minDepth(root->right);
        
        //
        if(minLeft == 0)
            return minRight+1;
        if(minRight == 0)
            return minLeft+1;
        return min(minLeft,minRight)+1;

    }
};

//BFS

//BFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while(!q.empty()) {
            depth += 1;
            int k = q.size();
            //traverse all the nodes in the same level
            
            for(int i = 0; i < k; i++) {
                TreeNode* node = q.front();
                if(node->left != NULL)
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);
                if(node->left == NULL && node->right == NULL)
                    return depth;
                q.pop();
                
            }
        }

    }
};