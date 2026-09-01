class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int l = 0;
        unordered_map<char, int> mp;
        int cnt = 0, mnLen = INT_MAX, sIdx = -1;
        for (int j = 0; j < t.size(); j++)
            mp[t[j]]++;

        for (int r = 0; r < n; r++) {
            if (mp[s[r]] > 0) {
                cnt++;
            }
            mp[s[r]]--;
            while (cnt == t.size()) {
                if ((r - l + 1) < mnLen) {
                    mnLen = r - l + 1;
                    sIdx = l;
                }
                mp[s[l]]++;
                if (mp[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
        }
        return sIdx == -1 ? "" : s.substr(sIdx, mnLen);
    }
};