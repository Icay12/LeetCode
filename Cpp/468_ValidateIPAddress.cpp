
class Solution {
    const string validIPv6Chars = "0123456789abcdefABCDEF";
    bool isValidIPv4Block(string block) {
        if(block.length() == 0 || block.length() > 3)
            return false;
        if(block.length() != 1 && block[0] == '0')
            return false;
        int a = 0;
        for(int i = 0; i < block.length(); ++i) {
            if(!isdigit(block[i]))
                return false;
            a = a*10 + (block[i] - '0');
        }
        return a < 256 ? true : false;
    }

    bool isValidIPv6Block(string block) {
        if(block.length() == 0 || block.length() > 4)
            return false;
        for(int i = 0; i < block.length(); ++i) {
            if(validIPv6Chars.find(block[i]) == string::npos) {
                return false;
            }
        }
        return true;
    }
    
public:
    string validIPAddress(string IP) {
        stringstream ss(IP);
    	string block;
    	// ipv4 candidate
    	if (IP.substr(0, 4).find('.') != string::npos) {
            for(int i = 0; i < 4; ++i) {
                if(!getline(ss,block,'.') || !isValidIPv4Block(block)) {
                    return "Neither";
                }
            }
            return ss.eof()? "IPv4" : "Neither";
        }
        //ipv5 candidate
        else if(IP.substr(0,5).find(':') != string::npos) {
            for(int i = 0; i < 8; ++i) {
                if(!getline(ss,block,':') || !isValidIPv6Block(block)) {
                    return "Neither";
                }
            }
            return ss.eof()? "IPv6" : "Neither";
        }
        return "Neither";
    }
};