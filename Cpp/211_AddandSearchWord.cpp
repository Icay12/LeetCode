class TrieNode {
public:
    TrieNode* next[26] = {NULL};
    bool isEndofWord;
    
    TrieNode() {
        isEndofWord = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.length(); ++i) {
            int index = word[i] - 'a';
            if(!cur->next[index]){
                cur->next[index] = new TrieNode();
            }
            cur = cur->next[index];
        }
        cur->isEndofWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(root, word, 0);
    }
    bool search(TrieNode* root, string word, int index) {
        if(root == NULL)
            return false;
        //last letter
        if(index == (int)word.length()-1) {
            if(word[index] == '.') {
                for(int i = 0; i < 26; ++i) {
                    if(root->next[i] && root->next[i]->isEndofWord) {
                        return true;
                    }
                }
                return false;
            }
            else {
                int i = word[index] - 'a';
                if(root->next[i] && root->next[i]->isEndofWord)
                    return true;
                else
                    return false;
            }
        }
        if(word[index] == '.') {
            for(int i = 0; i < 26; ++i) {
                if(search(root->next[i], word, index+1))
                    return true;
            }
            return false;
        }
        else {
            int i = word[index] - 'a';
            return search(root->next[i], word, index+1);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */