//naive 
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1)
            return x;
        //notice: use long because i*i may exceed INT_MAX
        for(long i = 0; i <= x/2; ++i) {   
            if((i*i) == x)
                return i;
            if((i*i) > x)
                return i - 1;
        }
        return x/2;
    }
};

//improve version, use division instead of multiplication
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1)
            return x;
        for(int i = 2; i <= x/2; ++i) {   
            if(i > x/i)
                return i - 1;
        }
        return x/2;
    }
};

//Newton method
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
            return 0;
        long r = x;
        // while(r *r > x)
        while(r*r > x) {
            r = (r + x / r)/2;
        }
        return r;
    }
};

//binary search
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
            return x;
        int begin = 1, end = x/2;
        while(begin < end) {
            int mid = (begin + end)/2;
            if(mid == x / mid)
                return mid;
            if(mid > x / mid) 
                end  = mid - 1;
            else{
                if(mid + 1 > x / (mid + 1))
                    return mid;
                begin = mid + 1;
            }
                
        }
        return begin;
    }
};