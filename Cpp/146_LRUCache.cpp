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