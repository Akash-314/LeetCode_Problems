class Solution {
public:
    string D2B(int n) {
        if (n == 0)
            return "0";
        string res;
        while (n > 0) {
            res += (n % 2) + '0';
            n /= 2;
        }
        reverse(res.begin(), res.end());
        while (res.size() < 8) {
            res = "0" + res;
        }
        return res;
    }
    bool isPalindromic(string s) {
        string b = "";
        for (int i = 0; i < s.size(); i++) {
            string bin = D2B(s[i]);
            b += bin;
        }
        string a = b;
        reverse(a.begin(), a.end());
        return a == b;
    }
};