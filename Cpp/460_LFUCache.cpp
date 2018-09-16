class LFUCache {
    int cap;
    int minFreq;
    unordered_map<int, pair<int,int>> valueFreq; // key -- {value, freq} 
    unordered_map<int, list<int>> frequency; // freq -- key list
    unordered_map<int, list<int>::iterator> hash; // key -- iterator
public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if(hash.count(key) == 0) {
            return -1;
        }
        else {
            int v = valueFreq[key].first;
            int f = valueFreq[key].second;
            valueFreq[key].second++;
            frequency[f].erase(hash[key]);
            frequency[f+1].push_front(key);
            hash[key] = frequency[f+1].begin();
            if(frequency[minFreq].size() == 0) {
                minFreq++;
            }
            return v;
        }
    }
    
    void put(int key, int value) {
        if(cap == 0)
            return;
        if(hash.count(key) == 0) {
            if(valueFreq.size() == cap) {
                int k = *prev(frequency[minFreq].end());
                hash.erase(k);
                valueFreq.erase(k);
                frequency[minFreq].pop_back();
            }
            
            valueFreq[key] = {value, 1};
            frequency[1].push_front(key);
            hash[key] = frequency[1].begin();
            minFreq = 1;
            
        }
        else {
            int f = valueFreq[key].second;
            valueFreq[key] = {value, f+1};

            frequency[f].erase(hash[key]);
            frequency[f+1].push_front(key);
            hash[key] = frequency[f+1].begin();
            if(frequency[minFreq].size() == 0) {
                minFreq++;
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */