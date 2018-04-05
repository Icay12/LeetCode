/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        TreeLinkNode* begin = NULL;
        TreeLinkNode* cur = root;
        TreeLinkNode* pre = NULL;
        while(cur != NULL) {
            while(cur != NULL) { //iterate at the same level
                if(cur->left) {
                    if(pre != NULL)
                        pre->next = cur->left;
                    if(begin == NULL)
                        begin = cur->left;
                    pre = cur->left;
                }
                if(cur->right) {
                    if(pre != NULL)
                        pre->next = cur->right;
                    if(begin == NULL)
                        begin = cur->right;
                    pre = cur->right;
                }
                cur = cur->next;
            }
            pre = NULL;
            cur = begin;
            begin = NULL;
            
        }
    }
};