class Solution {
public:
#define MOD 1000000007
#define ll long long
    ll Power(ll n, ll m) {
        if (m == 1)
            return n;
        if (m == 0)
            return 1;
        ll res = (Power(n, m / 2)) % MOD;

        res = (res * res) % MOD;
        if (m & 1)
            res = (res * n) % MOD;

        return res;
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size();

        vector<int> prefixSum(n, 0);

        prefixSum[0] = s[0] - '0';

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + (s[i] - '0');
        }

        vector<int> prefixNumber(n, 0);

        ll num = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0')
                num = ((num * 10) + (s[i] - '0')) % MOD;
            prefixNumber[i] = (int)num;
        }

        vector<int> nonZero(n, 0);

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0')
                count++;
            nonZero[i] = count;
        }

        int len = queries.size();

        vector<int> ans(len);

        for (int i = 0; i < len; i++) {
            int start = queries[i][0];
            int end = queries[i][1];

            int sum = 0;
            if (start == 0) {
                sum = prefixSum[end];
            } else {
                sum = prefixSum[end] - prefixSum[start - 1];
            }

            ll tempVal = 0;

            if (start == 0)
                tempVal = prefixNumber[end];
            else {
                ll a = prefixNumber[start - 1];
                int length = nonZero[end] - nonZero[start - 1];
                ll b = Power(10, length);

                a = (a * b) % MOD;
                ll c = prefixNumber[end];
                tempVal = (c - a + MOD) % MOD;
            }

            ll mul = (tempVal * (ll)sum) % MOD;

            ans[i] = (int)mul;
        }

        return ans;
    }
};
// class Solution {
// public:
//     #define MOD 1000000007
//     #define ll long long
//     ll Power(ll n, ll m) {
//         if(m == 1) return n;
//         if(m == 0) return 1;
//         ll res = (Power(n, m/2)) % MOD;
//         res = (res* res) % MOD;
//         if(m & 1) res = (res* n) % MOD;
//         return res;
//     }
//     vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
//         int n = s.size();
//         int m = queries.size();
//         vector<int> res(m);
//         vector<ll> prefSum(n);
//         vector<ll> prefC(n);
//         vector<ll> P(n+1,0);
//         if(s[0] != '0') P[0] = 1;

//         for(int i = 1; i <= n; i++){
//             P[i] = (P[i-1]*10)%MOD;
//         }

//         prefC[0] = (s[0] - '0');
//         prefSum[0] = (s[0] - '0');
//         for(int i = 1; i < n; i++){
//             prefSum[i] = prefSum[i-1] + (s[i] - '0');
//             if(s[i] != '0') prefC[i] = prefC[i-1]*10 + (s[i] - '0');
//             else  prefC[i] = prefC[i-1];
//         }

//         for(int i = 0; i < m; i++){
//             auto q = queries[i];
//             int l = q[0];
//             int r = q[1];

//             ll sum = 0;
//             if(l == 0) sum = prefSum[r];
//             else sum = prefSum[r] - prefSum[l-1];

//             ll conc;
//             if(l == 0) conc = prefC[r];
//             conc = (prefC[r]%MOD -  prefC[l-1] * Power(10, P[r])%MOD)%MOD;

//             ll ans = (sum * conc) % MOD;
//             res[i] = (int)ans;
//         }
//         return res;
//     }
// };