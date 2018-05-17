class BSTreeNode {
public:
    BSTreeNode* left;
    BSTreeNode* right;
    int val;
    int dup;
    int leftnums;
    
    BSTreeNode(int a) {
        val = a;
        dup = 1;
        left = NULL;
        right = NULL;
        leftnums = 0;
    }
    
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        if(nums.size() == 0)
            return res;
        BSTreeNode* root = NULL;
        reverse(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i) {
            // cout << nums[i] << endl;
            insertNode(root, nums[i], res, 0);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    void insertNode(BSTreeNode* &root, int num, vector<int>& res, int sum) {
        // if(root != NULL)
        //     cout << num << " " << root->val << endl;
        if(root == NULL) {
            root = new BSTreeNode(num);
            res.push_back(sum);
            return;
        }
        else if(num == root->val) {
            (root->dup)++;
            res.push_back(sum + root->leftnums);
            return;
        }
        else if(num > root->val) { // right child
            // cout << "right" << num<< " " << sum + root->leftnums + root->dup << endl;
            insertNode(root->right, num, res, sum + root->leftnums + root->dup);
            return;
        }
        else {
            // cout << "left" << num<< " " << sum << endl;
            (root->leftnums)++;
            insertNode(root->left, num, res, sum);
            return;
        }
        
    }
};