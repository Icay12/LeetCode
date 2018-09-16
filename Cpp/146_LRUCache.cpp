class LRUCache {
private:
    list<int> priority;
    int size;
    unordered_map<int, int> hash;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(hash.count(key) == 0)
            return -1;
        
        if(priority.front() != key) {
            priority.remove(key);
            priority.push_front(key);
        }
        
        return hash[key];
    }
    
    void put(int key, int value) {
        if(hash.count(key) == 0) {
            if(priority.size() == size) {
                int back = priority.back();
                priority.pop_back();
                hash.erase(back);
            }
            priority.push_front(key);
            hash[key] = value;
        }
        else {
            if(priority.front() != key) {
                priority.remove(key);
                priority.push_front(key);
            }
            hash[key] = value;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */



// O(1) store list::iterator in map, reduce the time cost in list.remove();

class LRUCache {
private:
    list<int> priority;
    int size;
    unordered_map<int, pair<int,list<int>::iterator>> hash;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(hash.count(key) == 0)
            return -1;
        
        if(priority.front() != key) {
            priority.remove(key);
            priority.push_front(key);
            hash[key].second = priority.begin();
        }
        
        return hash[key].first;
    }
    
    void put(int key, int value) {
        if(hash.count(key) == 0) {
            if(priority.size() == size) {
                int back = priority.back();
                priority.pop_back();
                hash.erase(back);
            }
            priority.push_front(key);
            hash[key].first = value;
            hash[key].second = priority.begin();
        }
        else {
            if(priority.front() != key) {
                priority.erase(hash[key].second);
                priority.push_front(key);
            }
            hash[key].first = value;
            hash[key].second = priority.begin();
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */


/////O(1)

class LRUCache {
    list<pair<int,int>> priority;
    int cap;
    unordered_map<int, list<pair<int,int>>::iterator > hash;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(hash.count(key) == 0) {
            return -1;
        }
        else {
            int res = (*hash[key]).second;
            if(priority.begin() != hash[key]) {
                priority.erase(hash[key]);
                priority.push_front({key,res});
                hash[key] = priority.begin();
            }
            return res;
        }
    }
    
    void put(int key, int value) {
        if(cap == 0)
            return;
        if(hash.count(key) == 0) {
            if(hash.size() == cap) {
                auto remove = *prev(priority.end());
                
                hash.erase(remove.first);
                priority.erase(prev(priority.end()));
                
            }
            
            priority.push_front({key,value});
            hash[key] = priority.begin();
            
        }
        else {
            priority.erase(hash[key]);
            priority.push_front({key,value});
            hash[key] = priority.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */