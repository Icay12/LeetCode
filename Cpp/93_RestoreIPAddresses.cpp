class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        for(int i = 1; i <= 3; ++i) {
            for(int j = 1; j <= 3; ++j) {
                for(int k = 1; k <= 3; ++k) {
                    for(int f = 1; f <= 3; ++f) {
                        if((i + j + k + f) == s.length()) {
                            int a = stoi(s.substr(0,i));
                            int b = stoi(s.substr(i,j));
                            int c = stoi(s.substr(i+j,k));
                            int d = stoi(s.substr(i+j+k,f));
                            if(a <= 255 && b <= 255 && c <= 255 && d <= 255) {
                                
                                string s1 = to_string(a)+"."+to_string(b)+"."+to_string(c)+"."+to_string(d); //000000 is not valid
                                if(s1.length() == s.length()+3)
                                    res.push_back(s1);
                            }
                        }
                    }
                    
                }
            }
        }
        return res;
    }
};