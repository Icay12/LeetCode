class TrieNode {
public:
    TrieNode* next[26] = {NULL};
    bool isEndofWord;
    TrieNode() {
        isEndofWord = false;
    }
    
    bool isWord() {
        return isEndofWord;
    }
    
    void setWord() {
        isEndofWord = true;
    }
    
};

class Trie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.length(); ++i) {
            int index = word[i] - 'a';
            if(!cur->next[index]) {
                cur->next[index] = new TrieNode();
            }
            cur = cur->next[index];
        }
        cur->setWord();
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.length(); ++i) {
            int index = word[i] - 'a';
            if(!cur->next[index]) {
                return false;
            }
            cur = cur->next[index];
        }
        return cur->isWord();

    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(int i = 0; i < prefix.length(); ++i) {
            int index = prefix[i] - 'a';
            if(!cur->next[index]) {
                return false;
            }
            cur = cur->next[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */