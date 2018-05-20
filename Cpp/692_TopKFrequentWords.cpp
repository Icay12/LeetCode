class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hash;
        for(string s : words) {
            hash[s]++;
        }
        auto compare = [](const pair<string,int>& a, const pair<string,int>& b){
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };

        typedef priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(compare)> my_bucket;
        my_bucket bucket(compare);

        for(auto word : hash) {
            bucket.push(word);
            if(bucket.size() > k)
                bucket.pop();
        }
        
        vector<string> res;
        while(!bucket.empty()) {
            res.push_back(bucket.top().first);
            bucket.pop();
        }
        reverse(res.begin(), res.end());
        return res;

    }
};