class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        int n = stations.size();
        double begin = 0, end = stations[n-1] - stations[0];
        
        while(end - begin > 0.000001) {
            double mid = (begin+end)/2;
            
            //calculate k_mid
            int k_mid = 0;
            for(int i = 0; i < n-1; ++i) {
                double dis = stations[i+1] - stations[i];
                k_mid += ceil(dis/mid) - 1;  
            }
            if(k_mid > K) {
                begin = mid;
            }
            else {
                end = mid;
            }            
        }
        return begin;
    }
};