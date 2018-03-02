class Solution {
public:
    string addBinary(string a, string b) {
        int al = (int)a.length() - 1;
        int bl = (int)b.length() - 1;
        int carry = 0;
        string res = "";
        while(al >= 0 || bl >= 0 || carry > 0) {
            if(al >= 0) {
                carry += (a[al--] - '0');
            }
            if(bl >= 0) {
                carry += (b[bl--] - '0');
            }
            res = (char)('0' + carry%2) + res;
            carry = carry / 2;
        }
        return res;
    }
};