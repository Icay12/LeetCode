class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b){return a[1] < b[1];});
        priority_queue<int> clen;
        int curtime = 0;
        
        for(int i = 0; i < courses.size(); ++i) {
            if(curtime + courses[i][0] <= courses[i][1]) {
                clen.push(courses[i][0]);
                curtime += courses[i][0];
            }
            // think of [[100,2],[32,50]], so we should check clen is empty here
            else if(!clen.empty() && courses[i][0] < clen.top()) {
                curtime = curtime - clen.top() + courses[i][0];
                clen.pop();
                clen.push(courses[i][0]);
            }
        }
        
        return clen.size();
    }
};