class Solution {
public:
    string getPermutation(int n, int k) {
        set<int> nums;
        for(int i = 1; i <= n; ++i) {
            nums.insert(i);
        }
        
        string res = "";
        
        k--;
        
        for(int i = n-1; i >= 0; --i) {
            int fac = factorial(i);
            cout << fac << endl;
            int index = k / fac;
            int p = *next(nums.begin(), index);
            cout << index << " "<< p << endl;
            char c = '0' + p;
            res += c;
            nums.erase(p);
            k = k % fac;
            
        }
        return res;
    }
    
    int factorial(int n) {
        if(n == 0 || n == 1)
            return 1;
        return n*factorial(n-1); 
    }
};
