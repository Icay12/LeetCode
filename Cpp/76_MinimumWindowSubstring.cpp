class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> charmap(128, 0);
        for(auto c : t)
            charmap[c]++;
        int end = 0, begin = 0, len = INT_MAX, head = 0, count = (int)t.size();
        while(end < s.size()) {
            if(charmap[s[end++]]-- > 0) {
                count--;
            }
            while(count == 0) {
                if(end - begin < len) {
                    len = end - begin;
                    head = begin;
                }
                if(charmap[s[begin++]]++ == 0) {
                    count++;
                }
            }
        }
        if(len == INT_MAX)
            return "";
        else
            return s.substr(head,len);
    }
};