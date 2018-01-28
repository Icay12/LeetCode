//brute solution Time Limit Exceeded 

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0)
            return 0;

        int maxarea = 0;
        
        for(int i = 0; i < heights.size(); ++i) {
            int minheight = heights[i];
            for(int j = i; j < heights.size(); ++j) {
                minheight = min(minheight, heights[j]);
                int rec = minheight * (j-i+1);
                maxarea = max(maxarea,rec);
            }
        }
        return maxarea;
    }
};




class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0)
            return 0;
        heights.push_back(0);
        vector<int> smallest;
        int maxArea = 0;
        for(int i = 0; i < heights.size(); ++i) {
            while(smallest.size() != 0 && heights[i] < heights[smallest.back()]) {
                int h = heights[smallest.back()];
                if(heights[i] != heights[smallest.back()])
                    smallest.pop_back();
                int area = 0;
                if(smallest.size() == 0)
                    area = h * i;
                else
                    area = h * (i - 1 - smallest.back());
                // cout << "pop" << area << endl;
                maxArea = max(maxArea, area);
            }
                
            smallest.push_back(i);
        }
        return maxArea;
    }
};


