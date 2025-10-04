// Fraction to Recurring Decimal

// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
// If the fractional part is repeating, enclose the repeating part in parentheses.If multiple answers are possible, return any of them.
// It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)
            return "0";

        
        string ans = "";
        if(numerator < 0 ^ denominator < 0)
            ans += "-";

        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

        ans += to_string(n/d);
        long long rem = n%d;

        if(rem == 0)
            return ans;
            
        ans += ".";
        unordered_map<long long,int> index;
        while(rem != 0){
            if(index.count(rem) != 0){
                ans.insert(index[rem],"(");
                ans += ')';
                break;
            }

            index[rem] = ans.size();
            rem *= 10;
            ans += to_string(rem/d);
            rem %= d;
        }

        return ans;
    }
};
