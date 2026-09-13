class Solution {
public:
    #define ll long long
    long long minOperations(vector<int>& nums) {
        vector<ll> ev, od;
        for(int l = 1; l <= 10; l++){
            int h = (l + 1) / 2;
            ll st = 1;
            for(int i = 1; i < h; i++) st *= 10;
            ll en = st * 10;

            for(ll i = st; i < en; i++){
                ll p = i, t = i;

                if(l % 2) t /= 10;
                while(t > 0){
                    p = p* 10 + (t % 10);
                    t /= 10;
                }
                if(p % 2 == 0) ev.push_back(p);
                else od.push_back(p);
            }
        }
        ll ans = 0;

        for(int x : nums){
            ll t = x;
            vector<ll>& v = (x % 2 == 0) ? ev : od;
            int id = lower_bound(v.begin(), v.end(), x) - v.begin();
            ll d1 = (id < v.size()) ? v[id] - x : LLONG_MAX;
            ll d2 = (id > 0) ? x - v[id  - 1] : LLONG_MAX;
            ans += min(d1, d2) / 2;
        }
        return ans;
    }
};