/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    TreeNode *it = NULL;
    vector<TreeNode*> st;
public:
    BSTIterator(TreeNode *root) {
        it = root;
        if(it != NULL) {
            TreeNode* cur = root;
            st.push_back(cur);
            cur = cur->left;
            while(cur != NULL) {
                st.push_back(cur);
                cur = cur->left;
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(st.empty()) {
            return false;
        }
        else {
            return true;
        }
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* top = st.back();
        st.pop_back();
        if(top->right != NULL) {
            TreeNode* cur = top->right;
            while(cur != NULL) {
                st.push_back(cur);
                cur = cur->left;
            }
        }
        return top->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */