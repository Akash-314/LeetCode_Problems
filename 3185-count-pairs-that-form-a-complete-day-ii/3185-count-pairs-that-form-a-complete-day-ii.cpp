class Solution {
public:
#define ll long long
#define mod 24
    long long countCompleteDayPairs(vector<int>& hours) {
        int n = hours.size();
        ll ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int req = (24 - hours[i] % mod) % mod;
            ans += mp[req];
            mp[hours[i] % mod]++;
        }
        return ans;
    }
};