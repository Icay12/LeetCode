class Solution {
public:
    string shortestPalindrome(string s) {
        int len = s.length();
        if(len == 0)
            return s;
        string revs = s;
        reverse(revs.begin(), revs.end());
        //first # is to avoid that s is palindrom itself
        //second # is to get the length of common prefix of the FULL string (add one more position)
        string news = s  + "#"+ revs + "#";
        int next[2*len + 2];
        getNext(news, next);
        return revs.substr(0, len - next[2*len+1]) + s;
    }
    void getNext(string news, int *next) {
        int n = news.size(); 
        next[0] = -1;
        for(int i = 0; i < n-1; ++i) {
            int k = next[i];
            
            while(k != -1 && news[i] != news[k])
                k = next[k];
            next[i+1] = k + 1;
            // cout << next[i+1] << endl;
        }
    }
};