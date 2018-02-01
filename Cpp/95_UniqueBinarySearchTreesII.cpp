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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return vector<TreeNode*>(); //in order to pass n = 0
        return gen(1, n);
    }
    vector<TreeNode*> gen(int begin, int end) {
        vector<TreeNode*> res;
        if(begin == end) {
            TreeNode* node = new TreeNode(begin);
            res.push_back(node);
        }
        else if(begin > end) {
            res.push_back(NULL);
        }
        else {
            for(int i = begin; i <= end; ++i) { //i is the root
                vector<TreeNode*> resleft, resright;
                resleft = gen(begin,i-1);
                resright = gen(i+1,end);
                for(int l = 0; l < resleft.size(); ++l) {
                    TreeNode* node = new TreeNode(i);
                    node->left = resleft[l];
                    for(int r = 0; r < resright.size(); ++r) {
                        node->right = resright[r];
                        res.push_back(node);
                        TreeNode* tmp = new TreeNode(i); //an address should be pushed only once
                        tmp->left = node->left;
                        node = tmp;
                    }
                }               
            }
        }
        return res;
        
            
    }
};