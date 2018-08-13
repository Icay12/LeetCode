class UF {
public:
    vector<int> id;
    vector<int> rank;
    int count;
    UF(int n) {
        count = n;
        for(int i = 0; i < n; ++i) {
            id.push_back(i);
            rank.push_back(1);
        }
    }
    int getCount () {
        return count;
    }
    int find(int a) {
        while(a != id[a]) {
            id[a] = id[id[a]];
            a = id[a];
        }
        return a;
    }
    void connect(int i, int j) {
        int a = find(i);
        int b = find(j);
        if(a == b)
            return;
        if(rank[a] > rank[b]) {
            id[b] = a;
        }
        else if(rank[a] < rank[b]) {
            id[a] = b;
        }
        else {
            id[b] = a;
            rank[a]++;
        }
        count--;
    }
    
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailID;
        unordered_map<string, string> emailAcc;
        int ID = 0;
        for(auto i : accounts) {
            string acc = i[0];
            for(int j = 1; j < i.size(); ++j) {
                string b = i[j];
                if(emailID.count(b) == 0)
                    emailID[b] = ID++;
                emailAcc[b] = acc;
            }
        }
        
        UF uf(ID);
        // cout << uf.getCount() << endl;
        // cout << "here1" << endl;
        for(auto i : accounts) {
            int email = emailID[i[1]];
            for(int j = 2; j < i.size(); ++j) {
                uf.connect(email, emailID[i[j]]);
            }
        }
        // cout << "here2" << endl;
        // cout << uf.getCount() << endl;
        vector< vector<string> > res(uf.getCount());
        unordered_map<int, set<string>> resMap;
        for(auto i : accounts) {
            for(int j = 1; j < i.size(); ++j) {
                resMap[uf.find(emailID[i[j]])].insert(i[j]);
            }
        }
        // cout << "here3" << endl;
        auto itr = resMap.begin();
        for(int i = 0; i < res.size(); ++i) {
            auto setItr = (itr->second).begin();
            res[i].push_back(emailAcc[*setItr]);
            while(setItr != (itr->second).end()) {
                res[i].push_back(*setItr);
                setItr++;
            }
            itr++;
        }
        // cout << "here" << endl;
        return res;
    }
};