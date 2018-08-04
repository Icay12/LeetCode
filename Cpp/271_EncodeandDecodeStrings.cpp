class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        int size = strs.size();
        res += to_string(size);
        res += "\\";
        for(int i = 0; i < size; ++i) {
            int len = strs[i].length();
            res+= to_string(len);
            res += "\\";
            res += strs[i];
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int p = 0;
        int size = 0;
        while(s[p] != '\\') {
            size = size*10 + (s[p] - '0');
            ++p;
        }
        ++p;
        for(int i = 0; i < size; ++i) {
            int len = 0;
            while(s[p] != '\\') {
                len = len*10 + (s[p] - '0');
                ++p;
            }
            ++p;
            res.push_back(s.substr(p, len));
            p += len;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));