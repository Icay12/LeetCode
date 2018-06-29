class MyCalendar {
private:
    vector<pair<int,int>> dates;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto p : dates) {
            if(  ! ((p.second <= start && p.second < end) || (p.first > start && p.first >= end))) {
                return false;
            }
        }
        dates.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */


 class MyCalendar {
private:
    set<pair<int,int>> dates;
    
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        set<pair<int,int>>::iterator itr = dates.lower_bound({start,end});
        if(itr!=dates.end() && itr->first < end)
            return false;
        if(itr!=dates.begin() && ((--itr)->second) > start)
            return false;
        dates.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */