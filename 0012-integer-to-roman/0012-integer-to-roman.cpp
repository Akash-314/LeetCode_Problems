class Solution {
public:
    string intToRoman(int num) {
        vector<int> val = {1,  4,   5,   9,   10,  40,  50, 90, 100, 400, 500, 900, 1000};
        vector<string> rom = {"I",  "IV", "V",  "IX", "X",  "XL", "L", "XC", "C",  "CD", "D",  "CM", "M"};
        string ans = "";
        for(int i = 12; i >= 0; i--){
            while(num >= val[i]){
                ans += rom[i];
                num -= val[i];
            }
        }
        return ans;
    }
};