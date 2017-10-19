class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        int p[12100] = {0};
        string result = "";
        for(int i = len1 - 1; i >= 0; --i) {
            for(int j = len2 - 1; j >= 0; --j) {
                int mul = (num1[i]-'0')*(num2[j]-'0');
                int sum = mul + p[i+j+1];
                p[i+j+1] = sum % 10;
                p[i+j] = sum / 10 + p[i+j];
            }
        }
        int i;
        while( i <= len1+len2-1 && p[i] == 0) {
            ++i;
        }
        for(; i <= len1+len2-1; ++i) {
            result += ('0' + p[i]);
        }
        if(result.length() == 0)
            result = "0";
        return result;
    }
};