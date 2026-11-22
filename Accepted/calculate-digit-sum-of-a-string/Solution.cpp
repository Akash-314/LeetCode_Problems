class Solution {
public:
    int f(string s) {
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            sum += s[i] - '0';
        }
        return sum;
    }

    string digitSum(string s, int k) {
        while (s.size() > k) {
            string ans = "";
            for (int i = 0; i < s.size(); i += k) {
                string t = s.substr(i, k);
                ans += to_string(f(t));
            }
            s = ans;
        }
        return s;
    }
};
