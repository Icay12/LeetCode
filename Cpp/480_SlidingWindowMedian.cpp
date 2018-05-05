class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s(nums.begin(), nums.begin() + k);
        vector<double> res;
        multiset<int>::iterator it = next(s.begin(), k / 2);
        for(int i = k; i <= (int)nums.size(); ++i) {
            it = next(s.begin(), k / 2);
            // cout << *it << endl;
            double mid = ((double)*it+ *prev(it, 1- k%2))/2.0; //here double should not be put outside, to prevent (*it + *...) is out of bound

            // cout << mid << endl;
            res.push_back(mid);
            if(i == (int)nums.size()) {
                return res;
            }
            s.insert(nums[i]);
            // if(nums[i] > mid) {
            //     it++;
            // }
            // else {
            //     it--;
            // }
            // cout << nums[i-k] << endl;
            s.erase(lower_bound(s.begin(),s.end(), nums[i-k]));
        }
    }
};