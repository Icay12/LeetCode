class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res = "";
        long long numer = numerator;
        long long denom = denominator;
        if(numerator == 0)
            return "0";
        if(numerator < 0 ^ denominator < 0) {
            res += '-';
        }
        //if here we use denom = -denominator, and denominator == INT_MIN, it cannot work;
        numer = numer < 0 ? -numer : numer;
        denom = denom < 0 ? -denom : denom;
        // cout << numer << " " << denom << endl;
        res+= to_string(numer / denom);
        long long reminder = numer % denom;
        if(reminder == 0)
            return res;
        res += '.';
        unordered_map<long long, long long> reminderMap;
        long long pos = res.length();
        // reminderMap[reminder] = pos++;
        while(reminder) {
            long long quotient = reminder * 10 / denom;
     
            if(reminderMap[reminder] != 0) {
                // cout << res << endl;
                res.insert(reminderMap[reminder],"(");
                // cout << res << endl;
                res.append(")");
                break;
            }    
            reminderMap[reminder] = pos++;
            res += to_string(quotient);
            reminder = reminder * 10 % denom;
            // cout << reminder << endl;
            
        }
        return res;
    }
};