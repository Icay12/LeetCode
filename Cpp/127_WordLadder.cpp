//one end version wrong
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        queue<string> toVisit;
        toVisit.push(beginWord);
        wordList.erase(remove(wordList.begin(), wordList.end(), beginWord), wordList.end());
        int res = 2;
        while(!toVisit.empty()) {
            // for(auto it = toVisit.begin(); it != toVisit.end(); ++it ) {
            int n = toVisit.size();
            for(int it = 0; it < n; ++it) {
                // string word = *it;
                // auto it = 
                string word = toVisit.front();
                toVisit.pop();
                // cout << word << " " << res << endl;
                for(int i = 0; i < word.length(); ++i) {
                    for(int a = 0; a < 26; ++a) {
                        string iword = word;
                        iword[i] = 'a' + a;
                        if(iword == endWord)
                            return res;
                        if(find(wordList.begin(), wordList.end(), iword) != wordList.end()) {
                            toVisit.push(iword);
                            wordList.erase(remove(wordList.begin(), wordList.end(), iword), wordList.end());
                        }
                    }
                }
            }
            res += 1;
        }
        return 0;
        
    }
};

//one end version right 
//!!!! Change vector to set, because the time complexity of find() for vector and set is different
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        queue<string> toVisit;
        toVisit.push(beginWord);
        wordDict.erase(beginWord);
        int res = 1;
        while(!toVisit.empty()) {
            int n = toVisit.size();
            for(int it = 0; it < n; ++it) {
                string word = toVisit.front();
                toVisit.pop();
                if(word == endWord)
                    return res;

                for(int i = 0; i < (int)word.length(); ++i) {
                    for(int a = 0; a < 26; ++a) {
                        string iword = word;
                        iword[i] = 'a' + a;
                        
                        if(wordDict.find(iword) != wordDict.end()) {
                            toVisit.push(iword);
                            wordDict.erase(iword);
                        }
                    }
                }
            }
            res += 1;
        }
        return 0;
        
    }
};

//two end version
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        if(wordDict.find(endWord) == wordDict.end())
            return 0;
        unordered_set<string> toVisitBegin;
        unordered_set<string> toVisitEnd;
        unordered_set<string> *head, *tail;
        toVisitBegin.insert(beginWord);
        head = &toVisitBegin;
        toVisitEnd.insert(endWord);
        tail = &toVisitEnd;
        wordDict.erase(endWord);
        int res = 2;
        while(!head->empty() && !tail->empty()) {
            // for(auto it = toVisit.begin(); it != toVisit.end(); ++it ) {
            if(head->size() > tail->size()) {
                unordered_set<string> *temp = tail;
                tail = head;
                head = temp;
            }
            int n = head->size();
            unordered_set<string> temp;
            for(auto it = head->begin(); it != head->end(); ++it) {
                string word = *it;

                cout << word << " " << res << endl;
                
                for(int i = 0; i < (int)word.length(); ++i) {
                    for(int a = 0; a < 26; ++a) {
                        string iword = word;
                        iword[i] = 'a' + a;
                        if(tail->find(iword) != tail->end())
                            return res;
                        if(wordDict.find(iword) != wordDict.end()) {
                            temp.insert(iword);
                            wordDict.erase(iword);
                        }
                    }
                }
            }
            res += 1;
            swap(*head,temp);
        }
        return 0;
        
    }
};