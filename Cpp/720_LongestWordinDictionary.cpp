class TrieNode {
public:
    TrieNode* next[26];
    int isWordEnd = 0;
    void addEnd() {
        isWordEnd++;
    }
    bool isEnd() {
        if(isWordEnd == 0)
            return false;
        return true;
    }
};

class TrieTree {
private:
    TrieNode* root = new TrieNode();

public:
    void insert(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.length(); ++i) {
            int index = word[i] - 'a';
            if(!cur->next[index]) {
                cur->next[index] = new TrieNode();
            }
            cur = cur->next[index];
        }
        cur->addEnd();
    }
    
//     bool search(string word) {
//         TrieNode* cur = root;
//         for(int i = 0; i < word.length(); ++i) {
//             int index = word[i] - 'a';
//             if(!cur->next[index]) {
//                 return false;
//             }
//             cur = cur->next[index];
//         }
//         return cur->isEnd();

//     }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.length(); ++i) {
            int index = word[i] - 'a';
            if(!cur->next[index] || !cur->next[index]->isEnd()) {
                return false;
            }
            cur = cur->next[index];
        }
        return cur->isEnd();

    }
    
    string search(vector<string>& words) {
        // sort(words.begin(), words.end());

        TrieNode* cur = root;
        int len = INT_MIN;
        string res = "";
        for(string word : words) {
            if(search(word)) {
                if((int)word.length() > len || ((int)word.length() == len) && word < res) {
                    res = word;
                    len = word.length();
                }
            }
        }
        return res;

    }
    
};


class Solution {
public:
    string longestWord(vector<string>& words) {
        TrieTree* trie = new TrieTree();
        int res = 0;
        for(string word : words) {
            trie->insert(word);
        }
        
        return trie->search(words);
    } 

 
};