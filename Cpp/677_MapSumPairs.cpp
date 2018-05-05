class TrieNode {
    public:
        TrieNode* next[26] = {NULL};
        int thisval = 0;
        bool isEndofWord = false;
        // TrieNode(int n) {
        //     thisval = n;
        // }
        void setEnd() {
            isEndofWord = true;
        }
        void update(int n) {
            thisval = n;
        }
        bool isEnd() {
            return isEndofWord;
        }
        int getVal() {
            return thisval;
        }
};

class MapSum {
public:
    /** Initialize your data structure here. */

    TrieNode* root;
    
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode* cur = root;
        for(int i = 0; i < (int)key.length(); ++i) {
            int index = key[i] - 'a';
            if(!cur->next[index]) {
                cur->next[index] = new TrieNode();
            }
            cur = cur->next[index];
        }
        cur->update(val);
        cur->setEnd();
    }
    
    int sum(string prefix) {
        TrieNode* cur = root;
        for(int i = 0; i < (int)prefix.length(); ++i) {
            int index = prefix[i] - 'a';
            if(!cur->next[index]) {
                return 0;
            }
            cur = cur->next[index];
        }
        
        return calroot(cur);
    }
    
    int calroot(TrieNode* root) {
        int res = 0;
        if(root->isEnd())
            res += root->getVal();
        for(int i = 0; i < 26; ++i) {
            if(root->next[i] != NULL) {
                res += calroot(root->next[i]);
            }
        }

        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */