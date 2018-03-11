class Solution {
public:
    string customSortString(string S, string T) {
        sort(T.begin(), T.end(), [&](char a, char b){ return S.find(a) < S.find(b); });
        // cout << S.find('c');
        return T;
    }
};


class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char, int> spos;
        for(int i = 0; i < S.length(); ++i) {
            spos[S[i]] = i;
        }
        sort(T.begin(), T.end(), [&](char a, char b){ return spos[a] < spos[b]; });
        // cout << S.find('c');
        return T;
    }
};