class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<pair<double,int>> ratio;
        
        for(int i = 0; i < wage.size(); ++i) {
            ratio.push_back({(double)wage[i]/quality[i], quality[i]});
        }
        
        sort(ratio.begin(), ratio.end(), [](pair<double,int> a, pair<double,int> b) {
            return a.first < b.first;
        });
        
        //max heap
        priority_queue<int> quality_queue;
        double sum = 0;
        double res = 0;
        
        for(int i = 0; i < K; ++i) {
            quality_queue.push(ratio[i].second);
            sum += ratio[i].second;
        }
        
        res = ratio[K-1].first*sum;
        
        for(int i = K; i < wage.size(); ++i) {
            quality_queue.push(ratio[i].second);
            sum += ratio[i].second;
            sum -= quality_queue.top();
            quality_queue.pop();
            
            res = min(res, sum * ratio[i].first);
        }
        
        return res;
        
        
    }
};