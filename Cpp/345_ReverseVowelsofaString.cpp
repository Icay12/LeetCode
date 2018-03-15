class Solution {
public:
    string reverseVowels(string s) {
        vector<char> dict(256,0);
        dict['a'] = 1;
        dict['e'] = 1;
        dict['i'] = 1;
        dict['o'] = 1;
        dict['u'] = 1;
        dict['A'] = 1;
        dict['E'] = 1;
        dict['I'] = 1;
        dict['O'] = 1;
        dict['U'] = 1;
        int i = 0, j = (int)s.length()-1;
        while(i < j) {
            while( i < j && dict[s[i]] != 1) ++i;
            while( i < j && dict[s[j]] != 1) --j;
            // cout << i << " " << j << endl;
            swap(s[i++],s[j--]);
        }
        return s;
    }
};

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = (int)s.size() - 1;
        while(i < j) {
            i = s.find_first_of("aeiouAEIOU", i);
            j = s.find_last_of("aeiouAEIOU", j);
            if(i < j)
                swap(s[i++],s[j--]);
        }
        return s;
    }
};
