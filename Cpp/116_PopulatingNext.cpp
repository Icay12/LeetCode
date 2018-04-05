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
        // TreeLinkNode *pre;
        if(root == NULL)
            return;
        TreeLinkNode* begin = root;
        while(root->left) {
            begin = root->left;
            root->left->next = root->right;
            while(root->next) {
                root->right->next = root->next->left;
                root->next->left->next = root->next->right;
                root = root->next;
            }
            root->right->next = NULL;
            root = begin;
        }
    }
};