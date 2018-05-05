class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxheap_left;
    priority_queue<int, vector<int>, greater<int>> minheap_right;
    double median;
    int total;
    
    MedianFinder() {
        total = 0;
    }
    
    void addNum(int num) {
        total += 1;
        if(total == 1) {
            median = num;
            // cout << median << endl;
            return;
        }
        if(total % 2 != 0) {  //odd
            if(num < median) {
                maxheap_left.push(num);
                median = maxheap_left.top();
                maxheap_left.pop();
            }
            else {
                minheap_right.push(num);
                median = minheap_right.top();
                minheap_right.pop();
            }
        }
        else { //even
            if(num < median) {
                maxheap_left.push(num);
                minheap_right.push(median);
            }
            else {
                maxheap_left.push(median);
                minheap_right.push(num);
            }
            median = (double)(maxheap_left.top() + minheap_right.top())/2.0;
        }
        // cout << median << endl;
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */