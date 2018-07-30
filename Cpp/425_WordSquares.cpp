class TrieNode {
public:    
    bool isEndofWord = false;
    TrieNode* next[26] = {NULL};

    TrieNode() {};
    vector<string> prefix;
};

class Trie {
    TrieNode* root;
    // void del(TrieNode* node) {
    //     delete node;
    // }
public:
    Trie() {
        root = new TrieNode();
    }
    
//     ~Trie() {
//         for(int i =0; i< 26;++i) {
//             if(root->next[i]) {
//                 del(root->next[i]);
//             }
//             del(root);
//         }
//     }
    
    void insert(string word) {
        TrieNode* cur = root;
        cur->prefix.push_back(word);
        for(char c : word) {
            int index = c - 'a';
            if(!cur->next[index]) {
                cur->next[index] = new TrieNode();
            }
            cur = cur->next[index];
            cur->prefix.push_back(word);
        } 
        cur->isEndofWord = true;
    }
    
    vector<string> findWordsWithPrefix(string prefix) {
        TrieNode* cur = root;
        for(char c : prefix) {
            int index = c - 'a';
            if(cur->next[index] == NULL) {
                return vector<string>(0);
            }
            cur = cur->next[index];
        } 
        return cur->prefix;
    }
};

class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> res;
        if(words.size() == 0)
            return res;
        vector<string> cur;
        Trie* trie = new Trie();
        for(auto word : words) {
            // cout << trie << endl;
            // cout << word << " ";
            trie->insert(word);
        }
        // cout << endl;
        helper(cur, res, trie, 0, words[0].size());
        delete trie;
        return res;
    }
    
    void helper(vector<string>& cur, vector<vector<string>>& res, Trie*& trie, int begin, int n) {
        if(begin == n) {
            res.push_back(cur);
            return;
        }
        string prefix = "";
        if(begin != 0) {
            for(string s : cur) {
                prefix += s[begin];
            }
        }
        vector<string> v = trie->findWordsWithPrefix(prefix);
        if(v.size() == 0)
            return;
        for(string s : v) {
            // cout << s << endl;
            cur.push_back(s);
            helper(cur, res, trie, begin+1, n);
            cur.pop_back();
        }
        return;    
            
    }
};