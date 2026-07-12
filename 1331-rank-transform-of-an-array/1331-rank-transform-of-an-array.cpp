class Solution {
public:
    typedef long long ll;
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        ans = arr;
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        int rank = 1;
        for (int i = 0; i < n; i++) {
            if (!mp.count(arr[i])) {
                mp[arr[i]] = rank;
                rank++;
            }
        }
        for (int i = 0; i < n; i++) {
            ans[i] = mp[ans[i]];
        }
        return ans;
    }
};