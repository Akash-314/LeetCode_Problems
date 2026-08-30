class Solution {
public:
    #define ll long long
    const ll mod = 1e9 + 7;

    ll power(ll x, ll y){
        ll ans = 1;
        while(y > 0){
            if(y & 1) ans = (ans * x) % mod;

            x = (x * x) % mod;
            y >>= 1;
        }
        return ans;
    }
    int sumDecoded(vector<long long>& nums) {
        ll n = nums.size();
        ll sum = 0;
        for(int i = 0; i < n; i++){
            ll w = nums[i] % 10;
            ll d = floor(nums[i] / 10);

            ll dt = d, wt = 0;
            while(dt){
                dt /= 10;
                wt++;            
            }
            ll wd = wt - w;
            ll pow = 1;
            for(int j = 0; j < wd; j++){
                pow *= 10;
            }
            ll x = d / pow;
            ll y = d % pow;
            sum = (sum + power(x , y)) % mod;
        }
        return sum % mod;
    }
};