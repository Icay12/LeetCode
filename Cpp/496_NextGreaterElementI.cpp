class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int,int> hash;
        vector<int> res(findNums.size(),-1);
        stack<int> st;
        for(int i = 0; i < findNums.size(); ++i) {
            hash[findNums[i]] = i;
        }
        
        for(auto a : nums) {
            while(!st.empty() && a > st.top()) {
                if(hash.count(st.top()) != 0) {
                    res[hash[st.top()]] = a;
                }
                st.pop();
            }
            
            st.push(a);
        }
        return res;
    }
};