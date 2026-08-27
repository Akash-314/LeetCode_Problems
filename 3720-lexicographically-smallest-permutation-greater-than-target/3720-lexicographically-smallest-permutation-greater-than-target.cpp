class Solution {
public:
    string ans = "";
    bool f(string& curr, vector<int>& cnt, string& tar, int i, bool grt) {
        if (i == tar.size()) {
            if (grt) {
                ans = curr;
                return true;
            } else
                return false;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if ((cnt[ch - 'a'] == 0) || (!grt and ch < tar[i]))
                continue;

            curr.push_back(ch);
            cnt[ch - 'a']--;
            bool great = grt || ch > tar[i];
            if (f(curr, cnt, tar, i + 1, great))
                return true;
            curr.pop_back();
            cnt[ch - 'a']++;
        }
        return false;
    }
    string lexGreaterPermutation(string s, string tar) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (int i = 0; i < n; i++)
            cnt[s[i] - 'a']++;
        string curr;
        f(curr, cnt, tar, 0, false);
        return ans;
    }
};