class Solution {
public:
    string below_20[19] ={"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    string below_100[8] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        else {
            string res = towords(num);
            return res.substr(1, res.length()-1);
        }
    }
    
    string towords(int num) {
        if(num >= 1000000000) {
            return towords(num/1000000000) + " Billion" + towords(num - 1000000000 * (num/1000000000));
        }
        else if(num >= 1000000) {
            return towords(num/1000000) + " Million" + towords(num - 1000000 * (num/1000000));
        }
        else if(num >= 1000) {
            return towords(num/1000) + " Thousand" + towords(num - 1000* (num/1000));
        }
        else if(num >= 100) {
            return towords(num/100) +  " Hundred" + towords(num - 100* (num/100));
        }
        else if(num >= 20) {
            return " " + below_100[num/10-2] +  towords(num - 10*(num/10));
        }
        else if(num > 0) {
            return " " + below_20[num-1];
        }
        else {
            return "";
        }
    }
    
};