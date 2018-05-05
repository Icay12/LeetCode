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
    
    void setNotWord() {
        isEndofWord = false;
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
        bool res = cur->isWord();
        if(cur->isWord())
            cur->setNotWord();
        return res;

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


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        
        vector<string> res;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(string word : words) {
            trie.insert(word);
        }
        
        string s = "";
        
        for(int i = 0; i < (int)board.size(); ++i) {
            for(int j = 0; j < (int)board[0].size(); ++j) {
                searchWords(board, i, j, trie, res, s+board[i][j], visited);
            }
        }
        
        return res;
    }
    
    void searchWords(vector<vector<char>>& board, int i, int j, Trie& trie, vector<string>& res, string s, vector<vector<bool>>& visited) {
        // cout << s << endl;
        if(trie.search(s)) {
            res.push_back(s);
        }
        if(!trie.startsWith(s))
            return;
        visited[i][j] = true;
        if(i+1 < (int)board.size() && !visited[i+1][j]) searchWords(board,i+1,j,trie,res,s+board[i+1][j], visited);
        if(i-1 >= 0 && !visited[i-1][j]) searchWords(board,i-1,j,trie,res,s+board[i-1][j], visited);
        if(j+1 < (int)board[0].size() && !visited[i][j+1]) searchWords(board,i,j+1,trie,res,s+board[i][j+1], visited);
        if(j-1 >= 0 && !visited[i][j-1]) searchWords(board,i,j-1,trie,res,s+board[i][j-1], visited);
        visited[i][j] = false;
        return;
    }
};