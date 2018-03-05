class Solution {
public:
    string simplifyPath(string path) {
        vector<string> address;
        stringstream ss(path);
        string addr;
        // int i = 1;
        while(getline(ss, addr, '/')) {
            // cout << i++ << addr << endl;
            if(addr == "." || addr == "")
                continue;
            if(addr == "..") {
                if(address.size() != 0)
                    address.pop_back();
            }
            else {
                address.push_back(addr);
            }
        }
        
        if(address.size() == 0)
            return "/";
        string res = "";
        for(int i = 0; i < address.size(); ++i) {
            res += "/";
            res += address[i];
        }
        return res;
    }
};