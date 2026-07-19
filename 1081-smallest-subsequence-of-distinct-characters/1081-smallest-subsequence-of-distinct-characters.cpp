class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<bool> taken(26, false);
        vector<int> lastIdx(26);
        for (int i = 0; i < n; i++) {
            int ch = s[i] - 'a';
            lastIdx[ch] = i;
        }
        string res;
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (taken[idx] == true)
                continue;
            while (res.size() > 0 and res.back() > s[i] and
                   lastIdx[res.back() - 'a'] > i) {
                taken[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(s[i]);
            taken[idx] = true;
        }
        return res;
    }
};