/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
    int countSameLetters(string a, string b) {
        int cnt = 0;
        for(int i = 0; i < 6; ++i) {
            if(a[i] == b[i])
                cnt++;
        }
        return cnt;
    }
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        unordered_map<string, unordered_map<int, unordered_set<string>>> hash;
        
        //generate sets for words which has the same number of same characters
        for(int i = 0; i < wordlist.size(); ++i) {
            for(int j = i+1; j < wordlist.size(); ++j) {
                int same = countSameLetters(wordlist[i],wordlist[j]);
                hash[wordlist[i]][same].insert(wordlist[j]);
                hash[wordlist[j]][same].insert(wordlist[i]);
            }
        }
        
        unordered_set<string> candidates;
        string cur = wordlist[rand()%(int)wordlist.size()]; //randomly choose a word from the list
        //make at most ten calls
        for(int i = 0; i < 10; ++i) {
            int a = master.guess(cur);
                if(a == 6)
                    return;
            //the first guess
            if(i == 0) {
                candidates = hash[cur][a];
                cur = *candidates.begin();
            }
            else {
                //calculate the intersection of candidates and hash[cur][a]
                unordered_set<string> temp;
                for(string s : candidates) {
                    if(hash[cur][a].find(s) != hash[cur][a].end())
                        temp.insert(s);
                }
                candidates = temp;
                cur = *candidates.begin();
            }
        }
        return;
        
    }
    

    
};