class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();
        long long l = 0, ans = 0;
        for (int r = 0; r < n; r++) {
            if (r >= 2 and s[r - 2] == 'a' and s[r - 1] == 'b' and
                s[r] == 'c') {
                l = r - 1;
            }
            ans += (r - l + 1);
        }
        return ans;
    }
};