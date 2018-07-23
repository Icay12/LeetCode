/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


//BFS
class Codec {
private:
    vector<string> split(string s) {
        istringstream iss(s);
        string tmp;
        vector<string> res;
        while(iss >> tmp) {
            res.push_back(tmp);
        }
        return res;
    }
    
    string compose(vector<string> v) {
        string res = "";
        for(string s : v) {
            res += " ";
            res += s;
        }
        return res.substr(1);
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "null";
        vector<string> v;
        queue<TreeNode*> q;
        q.push(root);
        v.push_back(to_string(root->val));
        
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; ++i) {
                TreeNode* tn = q.front();
                q.pop();
                if(tn->left) {
                    v.push_back(to_string(tn->left->val));
                    q.push(tn->left);
                }
                else {
                    v.push_back("null");
                }
                if(tn->right) {
                    v.push_back(to_string(tn->right->val));
                    q.push(tn->right);
                }
                else {
                    v.push_back("null");
                }
            }
        }
        
        while(v.back() == "null") {
            v.pop_back();
        }
        string res = compose(v);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v = split(data);
        queue<TreeNode*> q;
        int cnt = 1;

        if(v[0] == "null")
            return NULL;
        TreeNode* root = new TreeNode(stoi(v[0]));
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                if(cnt < v.size() && v[cnt] != "null") {
                    TreeNode* left = new TreeNode(stoi(v[cnt]));
                    node->left = left;
                    q.push(left);
                }
                cnt++;
                if(cnt < v.size() && v[cnt] != "null") {
                    TreeNode* right = new TreeNode(stoi(v[cnt]));
                    node->right = right;
                    q.push(right);
                }
                cnt++;
                q.pop();
                    
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));