class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        auto compare = [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.first < b.first;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(compare)> maxHeap(compare); // height, end
        int topH = 0;
        int topX = 0;
        int curX = 0;
        vector<pair<int, int>> res;
        if(buildings.size() == 0)
            return res;
        vector<int> last = {-1, -1, 0};
        buildings.push_back(last);

        for(int i = 0; i < buildings.size(); ++i) {
            vector<int> building = buildings[i];
            curX = building[0];

            //if separate with the previous buildings
            while(!maxHeap.empty() && (maxHeap.top().second < curX || curX == -1)) {
                if(maxHeap.top().second > topX) {
                    res.push_back(make_pair(topX, maxHeap.top().first));
                    cout << " 1 " << curX << endl;
                    topX = maxHeap.top().second;
                }
                maxHeap.pop();
                topH = maxHeap.top().second;
                if(maxHeap.empty()) {
                    res.push_back(make_pair(topX, 0));
                    cout << " 2 " << endl;
                }
                else if(curX != -1 && maxHeap.top().second >= curX) {
                    res.push_back(make_pair(topX, maxHeap.top().first));
                    cout << " 4 " << endl;
                }
            }

            while(!maxHeap.empty() && maxHeap.top().second == curX) {
                maxHeap.pop();
            }

            if(!maxHeap.empty()) {
                topH = maxHeap.top().first;
                topX = maxHeap.top().second;
            }
            else {
                topH = topH == building[2]? topH : 0;
                topX = curX;
            }
            // if overlapped with previous buildings
            if(building[2] > topH) {
                // res.push_back(make_pair(curX, topH));

                int j = i;
                while(buildings[i+1][1] == building[1] && buildings[i+1][2] > building[2])
                    i++;
                maxHeap.push(make_pair(buildings[i][2], building[1]));
                topH = buildings[i][2];
                topX = building[1];
                res.push_back(make_pair(curX, topH));
                for( ; j < i; ++j) {
                    maxHeap.push(make_pair(buildings[i][2], buildings[i][1]));
                }
                cout << " 3 " << endl;
            }
            else if(building[2] == topH) {
                if(!maxHeap.empty())
                    maxHeap.pop();
                maxHeap.push(make_pair(building[2], building[1]));
                topX = building[1];
            }

            else {
                maxHeap.push(make_pair(building[2], building[1]));
            }

        }
        return res;
    }
};