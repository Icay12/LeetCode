// two stacks
class MinStack {
private:
    vector<int> st;
    vector<int> min;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st.push_back(x);
        if(min.empty() || x <= min.back())  // must has =
            min.push_back(x);
    }
    
    void pop() {
        if(st.back() == min.back())
            min.pop_back();
        st.pop_back();
        
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return min.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */




 // one stacks
class MinStack {
private:
    vector<int> st;
    int min;
    bool hasElement;
public:
    /** initialize your data structure here. */
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int x) {
        if(x <= min) { // we get a new minimum, befor x, the minimum is min
            st.push_back(min);
            min = x;
        }
        st.push_back(x);
    }
    
    void pop() {
        int t = st.back();
        if(t == min) {
            st.pop_back();
            min = st.back();
            st.pop_back();
        }
        else 
            st.pop_back();
        
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */