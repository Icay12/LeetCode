class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> record;
        for(auto c : s) {
            ++record[c];
        }
        
        sort(s.begin(), s.end(), [&](char a, char b){ return record[a] > record[b] || (record[a] == record[b] && a < b);});
        return s;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> record;
        vector<string> ss(s.size()+1,"");
        for(auto c : s) {
            ++record[c];
        }
        for(auto it : record) {
            int n = it.second;
            char c = it.first;
            ss[n].append(n, c);
        }
        string res = "";
        for(int i = s.size(); i > 0; --i) {
            res.append(ss[i]);
        }
        return res;
        
    }
};

