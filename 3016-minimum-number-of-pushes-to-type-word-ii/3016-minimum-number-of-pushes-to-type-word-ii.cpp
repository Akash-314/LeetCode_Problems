class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
        int cnt = 1;
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[word[i]]++;
        }
        int i = 1;
        vector<int> freq;
        for(auto &x : mp)
            freq.push_back(x.second);

        sort(freq.rbegin(), freq.rend());
        for (auto x : freq) {
            ans += x * cnt;
            if (i == 8) {
                cnt++;
                i = 0;
            }
            i++;
        }
        return ans;
    }
};