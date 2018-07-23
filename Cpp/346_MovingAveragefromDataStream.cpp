class MovingAverage {
    queue<int> window;
    int max_size = 0;
    double sum = 0;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        max_size = size;
    }
    
    double next(int val) {
        if(window.size() < max_size) {
            window.push(val);
            sum += val;
            return sum / (int)window.size();
        }
        else {
            int front = window.front();
            window.pop();
            window.push(val);
            sum = sum + val - front;
            return sum / max_size;
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */