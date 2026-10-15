class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        unordered_set<string> st;
        for (int i = 1; i < n; i++) {
            for (int j = 2; j <= n; j++) {
                if (i == j or i > j)
                    continue;
                int g = __gcd(i, j);
                int p = i / g;
                int l = j / g;
                string prev = to_string(p);
                string last = to_string(l);
                string s = prev + '/' + last;
                st.insert(s);
            }
        }
        vector<string> ans(st.begin(), st.end());
        return ans;
    }
};