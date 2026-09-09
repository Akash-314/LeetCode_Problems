class Solution {
public:
#define ll long long
    long long countCommas(long long n) {
        if (1000 > n) return 0;
        ll count = 0;
        for (ll i = 1000; i <= n; i *= 1000) {
            count += n - i + 1;
        }
        return count;
    }
};