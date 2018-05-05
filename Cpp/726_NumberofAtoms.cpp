class Solution {
public:
    string countOfAtoms(string formula) {

        int i = 0;
        map<string, int> m = count(formula, i);
        string res = "";
        map<string,int>::iterator it;
        for(it = m.begin(); it != m.end(); ++it) {
            res += it->first;
            if(it->second > 1)
                res += to_string(it->second);
        }

        return res;

    }
    map<string, int> count(string formula, int& i) {
        string atom = "";
        int num = 0;
        map<string, int> m;
        while (i < formula.length() && formula[i] != ')') {
            //a new atom
            if (formula[i] >= 'A' && formula[i] <= 'Z') {
                if (atom != "") {
                    if (num == 0)
                        m[atom]++;
                    else {
                        m[atom] += num;
                        num = 0;
                    }
                }

                atom = formula[i];

                i++;
            }

                //the same atom
            else if (formula[i] >= 'a' && formula[i] <= 'z') {
                atom += formula[i++];
            }

                //number
            else if (formula[i] >= '0' && formula[i] <= '9') {
                num = num * 10 + (formula[i++] - '0');
            }

                // (
            else {
                i++; //skip (
                map<string, int> mm = count(formula, i);
                int nn = 0;
                i++; //skip )
                while (formula[i] >= '0' && formula[i] <= '9') {
                    nn = nn * 10 + (formula[i++] - '0');
                }
                map<string, int>::iterator it;
                for (it = mm.begin(); it != mm.end(); ++it) {
                    m[it->first] += (it->second) * nn;
                }
            }

        }

        if (atom != "") {
            if (num == 0)
                m[atom]++;
            else
                m[atom] += num;
        }
        return m;
    }

};