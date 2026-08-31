class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        int mxf = 0;
        int mxlen = 0;
        unordered_map<char, int> mp;
        for (int r = 0; r < n; r++) {
            mp[s[r]]++;
            mxf = max((int)mp[s[r]], mxf);
            while ((r - l + 1) - mxf > k) {
                mp[s[l]]--;
                l++;
            }
            if ((r - l + 1) - mxf <= k) {
                mxlen = max(mxlen, (r - l + 1));
            }
        }
        return mxlen;
    }
};