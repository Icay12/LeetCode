class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        //position of substr
        auto sort = [](const pair<int,int> &a, const pair<int,int> &b) {
                if(a.first < b.first)
                    return true;
                if(a.first == b.first && a.second > b.second)
                    return true;
                return false;
        };
        set<pair<int,int>,decltype(sort) > pos(sort);
        for(auto ss : dict) {
            int begin = 0;
            
            while(s.find(ss,begin) != string::npos) {
                int a = s.find(ss,begin);
                pos.insert({a, a - 1 + ss.length()});
                begin = a + 1;
                // cout << a << " " << a - 1 + ss.length() << endl;
            }
        }
        // cout << pos.size() << endl;
        if(pos.size() == 0)
            return s;
        int begin = pos.begin()->first;
        int end = pos.begin()->second;
        vector<int> v;
        for(auto p : pos) {
            if(p.first == begin)
                continue;
            else if(p.first <= end+1) {
                end = max(end, p.second);
            }
            else if(p.first > end+1) {
                v.push_back(begin);
                v.push_back(end+1);
                begin = p.first;
                end = p.second;
            }
        }
        v.push_back(begin);
        v.push_back(end+1);
        // cout << v.size() << endl;
        for(int i = (int)v.size()-1; i >= 0; --i) {
            // cout << v[i] << endl;
            if(i % 2) {
                s.insert(v[i], "</b>");
            }
            else {
                s.insert(v[i], "<b>");
            }
        }
        
        return s;
        
    }
};