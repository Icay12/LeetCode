class HitCounter {
private:
    int count;
    list<int> li;
public:
    /** Initialize your data structure here. */
    HitCounter() {
        count = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        li.push_back(timestamp);
        count++;
        
        while(!li.empty() && timestamp - li.front() >= 300) {
            li.pop_front();
            count--;
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while(!li.empty() && timestamp - li.front() >= 300) {
            li.pop_front();
            count--;
        }
        return count;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */