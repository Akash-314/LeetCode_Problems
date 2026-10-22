class Solution {
public:
#define ll long long
    bool isPrime(ll n) {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;

        for (ll i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
    long long sumOfLargestPrimes(string s) {
        int n = s.size();
        set<ll> temp;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            string t = "";
            ll a;
            for (int j = i; j < n; j++) {
                t += s[j];
                a = stoll(t);
                if (isPrime(a)) {
                    temp.insert(a);
                }
            }
        }
        int k = 3;
        for (auto it = temp.rbegin(); it != temp.rend(); it++) {
            if (k == 0)
                break;
            ans += *it;
            k--;
        }

        return ans;
    }
};