class Solution {
public:
    int countPrimes(int n) {
        vector<bool> Primes(n,true);
        int maxLine = (int)sqrt(n);
        if(n == 2 || n == 1 || n == 0) {
            return 0;
        }
        Primes[0] = Primes[1] = false;
        for(int j = 4; j < n; j += 2) { 
            Primes[j] = false;
        }
        for(int i = 3; i <= maxLine; i+=2) {
            if(Primes[i]) {
                for(int j = i * i; j < n; j += i) { //smart idea! 1. from i * i; 2. +=i
                    Primes[j] = false;
                }
            }
            
        }
        return count(Primes.begin(),Primes.end(),true);
    }
    
};