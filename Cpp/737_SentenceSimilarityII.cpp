class UF {
    vector<int> id;
    vector<int> rank;
public:
    UF(int n) {
        id = vector<int>(n, 0);
        rank = vector<int>(n, 0);
        for(int i = 0; i < n; ++i) {
            id[i] = i;
        }
    }
    
    int find(int i) {
        while(i != id[i]) {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
    
    bool isconnected(int i, int j) {
        return find(i) == find(j);
    }
    
    void connect(int i, int j) {
        int a = find(i);
        int b = find(j);
        if(a == b)
            return;
        if(rank[a] > rank[b]) {
            id[b] = a;
        }
        else if(rank[b] > rank[a]) {
            id[a] = b;
        }
        else {
            id[b] = a;
            rank[a]++;
        }
    }
};


class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if(words1.size() != words2.size())
            return false;
        //map string and id
        unordered_map<string,int> hash;
        int n = words1.size();
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(hash.count(words1[i]) == 0 )
                hash[words1[i]] = cnt++;
            if(hash.count(words2[i]) == 0 )
                hash[words2[i]] = cnt++;
        }
        for(auto p : pairs) {
            if(hash.count(p.first) == 0)
                hash[p.first] = cnt++;
            if(hash.count(p.second) == 0)
                hash[p.second] = cnt++;
        }
        UF uf(cnt);
        for(auto p : pairs) {
            uf.connect(hash[p.first],hash[p.second]);
        }
        
        for(int i = 0; i < n; ++i) {
            if(!uf.isconnected(hash[words1[i]],hash[words2[i]]))
                return false;
        }
        return true;
        
    }
};